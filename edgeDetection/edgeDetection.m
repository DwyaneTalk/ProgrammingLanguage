function edgeDetection()
    clear all;
    close all;
    clc;
    
    im_gray = rgb2gray(imread('lena.jpg'));
    figure(2);
    subplot(2, 3, 1);
    imshow(im_gray);
    title('1��ԭʼͼ��');
    im_db = double(im_gray);

    gaus_m = fspecial('gaussian', [5 5]);   %5x5��˹�˲�ģ��
    im_gaus = imfilter(im_db, gaus_m, 'replicate'); %��˹�˲�
    subplot(2, 3, 2);
    imshow(uint8(im_gaus));
    title('2��5x5��˹ģ���˲�');
    
    sobel_m = fspecial('sobel');        %3x3��ֱsobelģ�棨���ˮƽ��Ե��
    edge_x = imfilter(im_gaus, sobel_m, 'replicate');    %Sobel����ˮƽ��Ե���
    edge_y = imfilter(im_gaus, sobel_m', 'replicate');   %Sobel������ֱ��Ե���
    edge = sqrt(edge_x .^2 + edge_y .^2);       %��Եǿ��
    subplot(2, 3, 3);
    imshow(uint8(edge));
    title('3��Sobel���Ӽ�⵽�ı�Ե')
    
    neg_edge = non_max(edge, edge_x, edge_y);   %�Ǽ���ֵ����
    subplot(2, 3, 4);
    imshow(uint8(neg_edge));
    title('4���Ǽ���ֵ���ƽ��');
    
    im_edge_v1 = double_thr_v1(neg_edge, 200, 180);
    subplot(2, 3, 5);
    imshow(im_edge_v1);
    title('5����ֵ����ʵ��1���');    
    
    im_edge_v2 = double_thr_v2(neg_edge, 200, 180);
    subplot(2, 3, 6);
    imshow(im_edge_v2);
    title('6����ֵ����ʵ��2���');
end
%�Ǽ���ֵ����
function neg_edge = non_max(edge, edge_x, edge_y)
    [row, col] = size(edge);
    neg_edge = zeros(row, col);
    for x = 2 : row -1
        for y = 2 : col - 1;
            grad_x = edge_x(x, y);
            grad_y = edge_y(x, y);
            grad   = edge(x, y);
            if grad == 0                    % �ݶ�Ϊ0�������Ǳ�Ե
                continue;
            end
            if abs(grad_x) > abs(grad_y)    %��Ե����Ϊ��-45��45
                edge_tan = grad_y / grad_x;
                edge_P2 = edge(x+1, y);
                edge_P4 = edge(x-1, y);
                if edge_tan >= 0      %��Ե����Ϊ��0��45
                    edge_P1 = edge(x+1, y+1);
                    edge_P3 = edge(x-1, y-1);
                else                        %��Ե����Ϊ��-45��0
                    edge_P1 = edge(x+1, y-1);
                    edge_P3 = edge(x-1, y+1);
                end
                edge_M1 = edge_P1 * abs(edge_tan) + edge_P2 * (1 - abs(edge_tan));
                edge_M2 = edge_P3 * abs(edge_tan) + edge_P4 * (1 - abs(edge_tan));
            else                            %��Ե����Ϊ��45��135
                edge_ctn = grad_x / grad_y;
                edge_P2 = edge(x, y+1);
                edge_P4 = edge(x, y-1);
                if edge_ctn > 0      %��Ե����Ϊ��45��90
                    edge_P1 = edge(x+1, y+1);
                    edge_P3 = edge(x-1,  y-1);
                else                        %��Ե����Ϊ��45��135
                    edge_P1 = edge(x-1, y+1);
                    edge_P3 = edge(x+1, y-1);
                end
                edge_M1 = edge_P1 * abs(edge_ctn) + edge_P2 * (1 - abs(edge_ctn));
                edge_M2 = edge_P3 * abs(edge_ctn) + edge_P4 * (1 - abs(edge_ctn));
            end
            if grad > edge_M1 && grad > edge_M2
                neg_edge(x, y) = grad;
            end
        end 
    end
 %   max_value = max(neg_edge(:));
 %   neg_edge = neg_edge * 255 / max_value;
end
%�ݹ�ʵ����ֵ����
function im_edge = double_thr_v1(edge, th_max, th_min)
    [row ,col] = size(edge);
    im_edge = uint8(zeros(row, col));
    for x = 1 : row
        for y = 1 :col
            if edge(x, y) > th_max && im_edge(x, y) ~= 255 
                im_edge(x, y) = 255;
                im_edge = connection(im_edge, edge, x, y, th_min);
            end
        end
    end
end
function im_edge = connection(im_edge, edge, x, y, th_min)
    list = [ 1,  1,  1,  0, -1, -1, -1,  0;
             1,  0, -1, -1, -1,  0,  1,  1];
    for i = 1 : 8
        xi = (x + list(1, i));
        yi = (y + list(2, i));
        if xi > 0 && yi > 0 && edge(xi, yi) > th_min && im_edge(xi, yi) ~= 255
            im_edge(xi, yi) = 255;
            im_edge = connection(im_edge, edge, xi, yi, th_min);
        end
    end
end
%����ģ��ݹ�ʵ����ֵ����
function im_edge = double_thr_v2(edge, th_max, th_min)
    [row, col] = size(edge);
    MAXSIZE = row * col;
    list = [ 1,  1,  1,  0, -1, -1, -1,  0;
             1,  0, -1, -1, -1,  0,  1,  1];

    seed = find(edge > th_max);
    num = numel(seed);
    im_edge = zeros(row, col);
    im_edge(seed) = 255;
    
    seed_x = zeros(MAXSIZE, 1);
    seed_y = zeros(MAXSIZE, 1);
    seed_x(1 : num, 1) = uint8((seed - 1) / col + 1);
    seed_y(1 : num, 1) = uint8(mod((seed - 1), col) + 1);
    
    front = 1;
    rear = num + 1;
    while front ~= rear
        pos_x = seed_x(front);
        pos_y = seed_y(front);
        front = front + 1;
        for i = 1 : 8
            pos_xi = pos_x + list(1, i);
            pos_yi = pos_y + list(2, i);
            if pos_xi >0 && pos_yi >0 && edge(pos_xi, pos_yi) > th_min && im_edge(pos_xi, pos_yi)  ~= 255
                im_edge(pos_xi, pos_yi) = 255;
                seed_x(rear) = pos_xi;
                seed_y(rear) = pos_yi;
                rear = rear + 1;
            end
        end
    end
end
