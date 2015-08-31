function curvityCalculation()
%% ��ʼ����
clear all;
close all;
clc;

im_gray = double(rgb2gray(imread('plane.jpg')));
figure(1);

%% Kass���Դ���
% corner_list1 = Kass_detection(im_gray, 0.5, 'a');
% subplot(2, 2, 1);
% imshow(uint8(im_gray));
% hold on;
% [pos_row, pos_col] = find(corner_list1 == 1);
% plot(pos_col, pos_row, 'r*');
% title('1��Kass�Ĺ�ʽ1');
% 
% corner_list2 = Kass_detection(im_gray, 0.5, '-a');
% subplot(2, 2, 2);
% imshow(uint8(im_gray));
% hold on;
% [pos_row, pos_col] = find(corner_list2 == 1);
% plot(pos_col, pos_row, 'r*');
% title('2��Kass�Ĺ�ʽ2');
% 
% corner_list3 = Kass_detection(im_gray, 0.3, 't');
% subplot(2, 2, 3);
% imshow(uint8(im_gray));
% hold on;
% [pos_row, pos_col] = find(corner_list3 == 1);
% plot(pos_col, pos_row, 'r*');
% title('3��Kass�Ĺ�ʽ3');
% 
% corner_list4 = Kass_detection(im_gray, 0.3, '-t');
% subplot(2, 2, 4);
% imshow(uint8(im_gray));
% hold on;
% [pos_row, pos_col] = find(corner_list4 == 1);
% plot(pos_col, pos_row, 'r*');
% title('4��Kass�Ĺ�ʽ4');

%% Moravec��Harris���Դ���
% moravec_list1 = Moravec_detection(im_gray, 0.6, 1); %��˹��Ȩƽ��
% [pos_row, pos_col] = find(moravec_list1 == 1);
% subplot(2, 2, 1);
% imshow(uint8(im_gray));
% hold on;
% plot(pos_col, pos_row, 'r*');
% title('1��Moravec�����+��˹ƽ��');
% 
% moravec_list2 = Moravec_detection(im_gray, 0.6, 0); %����ƽ��
% [pos_row, pos_col] = find(moravec_list2 == 1);
% subplot(2, 2, 2);
% imshow(uint8(im_gray));
% hold on;
% plot(pos_col, pos_row, 'r*');
% title('2��Moravec�����+����ƽ��');
% 
% harris_list1 = Harris_detection(im_gray, 0.06, 0.2, 1);   %��˹��Ȩƽ��
% [pos_row, pos_col] = find(harris_list1 ==1);
% subplot(2, 2, 3);
% imshow(uint8(im_gray));
% hold on;
% plot(pos_col, pos_row, 'r*');
% title('3��Harris�����+��˹ƽ��');
% 
% harris_list2 = Harris_detection(im_gray, 0.06, 0.2, 0);   %����ƽ��
% [pos_row, pos_col] = find(harris_list2 ==1);
% subplot(2, 2, 4);
% imshow(uint8(im_gray));
% hold on;
% plot(pos_col, pos_row, 'r*');
% title('4��Harris�����+����ƽ��');

%% Susan��������Դ���
corner_list = Susan_detection(im_gray, 100, 0.55, 0);
[pos_row, pos_col] = find(corner_list == 1);
subplot(1, 2, 1);
imshow(uint8(im_gray));
hold on;
plot(pos_col, pos_row, 'r*');
title('1��Susan��������Դ���')

%% ��Ե�ݶȼ�����ʲ��Դ���

end

function im_corner = Susan_detection(im_in, th_t, th_g, percent)
    [row, col] = size(im_in);
    im_grad = zeros(row, col);
    w_size = 3;
    n_max = 37;
    th_g = (n_max - 1) * th_g; %�ǵ���ȡ
    
    for x = 1 + w_size : row - w_size;
        for y = 1 + w_size : col - w_size
            count = 0;
            for i = -w_size : w_size    %��Ӧ7x7=49�Ĵ���
                for j = -w_size : w_size
                    if i ^2 + j ^2 <= 10 && ~( i==0 && j==0)    %������37�Ĵ���
                        if abs(im_in(x,y) - im_in(x+i, y+j)) <= th_t
                            count = count + 1;
                        end
                    end
                end
            end
            if count >=  th_g
                im_grad(x,y) = 0;
            else
                im_grad(x,y) = th_g - count;
            end
        end
    end
    
    im_corner = non_max(im_grad, percent);
end

function im_corner = Harris_detection(im_in,lambda, percent, b_gauss)
%    fx = [-2 -1 0 1 2];
    fx = [-1 0 1;-1 0 1;-1 0 1];    %ʹ�ø�˹������һ��΢��ģ��Ч������
%    fy = [-2;-1;0;1;2];
    fy = [-1 -1 -1;0 0 0;1 1 1];   
    Mx = filter2(fx, im_in);
    My = filter2(fy, im_in);
    Mx2=Mx .* Mx;
    My2=My .* My;
    MxMy = Mx .* My;
    
    if b_gauss
        H = fspecial('gaussian', [5 5], 2);
    else
        H = fspecial('average', [3 3]);
    end
    A = filter2(H, Mx2);
    B = filter2(H, My2);
    C = filter2(H, MxMy);

    im_grad = A .* B - C .* C - lambda * (A + B);
    im_corner = non_max(im_grad, percent);
end

function im_corner = Moravec_detection(im_in, percent, b_gauss)
    [row, col] = size(im_in);
    im_grad = zeros(row, col);
 %    fx = [-2 -1 0 1 2];
    fx = [-1 0 1;-1 0 1;-1 0 1];    %ʹ�ø�˹������һ��΢��ģ��Ч������
%    fy = [-2;-1;0;1;2];
    fy = [-1 -1 -1;0 0 0;1 1 1];   
    Mx = filter2(fx, im_in);
    My = filter2(fy, im_in);
    Mx2=Mx .* Mx;
    My2=My .* My;
    MxMy = Mx .* My;
    
    if b_gauss
        H = fspecial('gaussian', [5 5], 1);
    else
        H = fspecial('average', [3 3]);
    end
    A = filter2(H, Mx2);
    B = filter2(H, My2);
    C = filter2(H, MxMy);
    
    for x = 1 : row
        for y = 1 : col
            if (Mx2(x, y) + My2(x ,y))~=0
                im_grad(x, y) = (A(x,y) * My2(x,y) + 2 * C(x,y) * MxMy(x,y) + B(x,y) * Mx2(x,y))/(Mx2(x,y) + My2(x,y));
            end
        end
    end
    
    im_corner = non_max(im_grad, percent);
end

function corner_list = Kass_detection(im_in, percent, opt)
    [row, col] = size(im_in);
    im_grad = zeros(row, col);
    fx = [-2 -1 0 1 2]; %ˮƽ����ģ��
    fy = [-2;-1;0;1;2]; %��ֱ����ģ��
    Mx = filter2(fx, im_in);    %ˮƽ�ݶ�
    My = filter2(fy, im_in);    %��ֱ�ݶ�
    Mxx= filter2(fx, Mx);
    Mxy= filter2(fy, Mx);
    Myx= filter2(fx, My);
    Myy= filter2(fy, My);
    
    for x = 1 : row;
        for y = 1 : col
            Mx2 = Mx(x, y) * Mx(x, y);
            My2 = My(x, y) * My(x, y);
            if (Mx2 + My2) ~= 0
                MxMy= Mx(x, y) * My(x, y);
                switch(opt)
                    case 'a'
                        im_grad(x, y) = ( My2 * Mxx(x, y) - MxMy * Myx(x, y) + Mx2 * Myy(x, y) - MxMy * Mxy(x, y)) / ((Mx2 + My2) ^ 1.5);
                    case '-a'
                        im_grad(x, y) = ( My2 * Mxx(x, y) - MxMy * Myx(x, y) - Mx2 * Myy(x, y) + MxMy * Mxy(x, y)) / ((Mx2 + My2) ^ 1.5);
                    case 't'
                        im_grad(x, y) = ( Mx2 * Myx(x, y) - MxMy * Mxx(x, y) + My2 * Mxy(x, y) - MxMy * Myy(x, y)) / ((Mx2 + My2) ^ 1.5);
                   case '-t'
                        im_grad(x, y) = (-Mx2 * Myx(x, y) + MxMy * Mxy(x, y) + My2 * Mxy(x, y) - MxMy * Myy(x, y)) / ((Mx2 + My2) ^ 1.5);
                end    
            end
        end
    end    
    corner_list = non_max(im_grad, percent);    %�Ǽ���ֵ���ƺ���ֵ����
end

function im_out = non_max(im_in, rate)
    [row, col] = size(im_in);
    im_out = zeros(row, col);
    max_value = max(im_in(:));
    th_value = max_value * rate;
    list = [ 1,  1,  1,  0, -1, -1, -1,  0;
             1,  0, -1, -1, -1,  0,  1,  1];
    
    for i = 2 :row-1
        for j = 2 :col-1
            im_out(i,j) = 1;
            if im_in(i,j) <= th_value
                im_out(i,j) = 0;
                continue;
            end
            for l = 1 : 8;
                x = i + list(1,l);
                y = j + list(2,l);
                if im_in(i,j) <= im_in(x,y)
                    im_out(i, j) = 0;
                    break;
                end
            end
        end
    end
end






