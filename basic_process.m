%% �ļ����
function basic_process()
    clear;
    clc;
    im_rgb = imread('lena.jpg');
    im_gray = rgb2gray(im_rgb);
%% ͼ���ʾ
%   ����ֱ��ͼ��ͳ��ͼ�����ض����ȼ����ص���Ŀ����ʾÿ�����ȼ���ͼ����ռ�ı�����
%   ͼ��Աȶȣ�ͨ��ͼ�����ȷ�Χ��������������ֵ�ķ�ɢ�����
%   ��ֵ����ͨ��ѡ���ض����ط�Χ�ڵ�������ѡ��ͼ���е�Ŀ�꣬��Ҫ������һ(�̶�)��ֵ���������Ӧ��ֵ����
    figure(1);
    subplot(5,2,1);
    imshow(im_gray);
    title('ԭʼͼ��');
    subplot(5,2,2);
    hist_t = imhist_t(im_gray);
    stem(0:255, hist_t, 'Marker', 'none');
    title('ԭʼֱ��ͼ');
%% ������
%   ��������ͨ������ԭʼͼ�����ص�ĺ���ֵ��Ϊ��ͼ���Ӧλ������ֵ���Ӷ�ʵ��ͼ��ֱ��ͼ���Աȶȵȱ仯
%   �������������ֱ��ͼ�����������滯��ֱ��ͼ���⻯��������ӳ�䣨���͡������ԣ�����ֵ�����
    subplot(5,2,3);
    im_gray_line_process = im_line_process(im_gray, 1.2, 10);
    imshow(im_gray_line_process);
    title('���͵�����ͼ��');
    subplot(5,2,4);
    hist_t = imhist_t(im_gray_line_process);
    stem(0:255, hist_t, 'Marker', 'none');
    title('���Ե�����ֱ��ͼ');

%   ֱ��ͼ���滯����ֱ��ͼ������չ����λ��ʹ�亭������256���Ҷ����ؼ�
%   ʵ�֣���ÿ�����ص㰴�գ�Nx,y = (Nmax - Nmin) * (Ox,y - Omin) / (Omax - Omin) + Nmin �������ͱ任
%   ����ֱ��ͼ���滯�����Ա任�������ǿ���ģ����滯����Իָ�ԭʼͼ�����ֱ��ͼ
    [im_norm, hist_n] = hist_norm(im_gray, 0, 255);
    subplot(5,2,5);
    imshow(im_norm);
    title('ֱ��ͼ���滯ͼ��');
    subplot(5,2,6);
    stem(0:255, hist_n, 'Marker', 'none');
    title('���滯ֱ��ͼ');
    
%   ֱ��ͼ���⻯��ͨ���ʺ����۵ķ����Ա仯����ǿͼ��ĶԱȶȺ�����
%   ���㹫ʽ���£���ԭq���ȼ������ر��Lookup(q)���ؼ���(Nmax - Nmin)/ N^2�Ǽ��轫����M*N������ƽ���ֵ�(Nmax
%   - Nmin)�����ؼ���SUM(Hist(i))��ԭͼ��0-q���ؼ��������ظ����ۼ�
%   Lookup(q) = (Nmax - Nmin)/ (M*N) * SUM(Hist(i)) i=0����q
%   Nx,y = Lookup(Ox,y)
%   ֱ��ͼ���⻯�ķ����Ա仯�������ǲ�����ģ����ܹ�ͨ��ֱ��ͼ���⻯���ͼ��ָ���ԭʼͼ��
%   ͼ�񾭹����͵����㣬����ı�ֱ��ͼ���⻯�Ľ�������Ծ���ֱ��ͼ���滯������ı�ֱ��ͼ���⻯�Ľ��
    [im_equa, hist_e] = hist_equa(im_gray);
    subplot(5,2,7);
    imshow(im_equa);
    title('ֱ��ͼ���⻯ͼ��');
    subplot(5,2,8);
    stem(0:255, hist_e, 'Marker', 'none');
    title('���⻯ֱ��ͼ');
    
%   ��ֵ������
    im_thsd = threshold_const(im_gray, 160);
    subplot(5,2,9);
    imshow(im_thsd);
    title('160��ֵ��ֵ��ͼ��');
    im_otsu = threshold_otsu(im_gray);
    subplot(5,2,10);
    imshow(im_otsu);
    title('Otsu������ֵ��ֵ��ͼ��')
%% Ⱥ����
    figure(2);
    subplot(2,3,1);
    imshow(im_gray);
    title('ԭʼͼ��');
    
    subplot(2,3,2);
    ave_template = average_template(10);
    im_ave = im_convolve(im_gray, ave_template);
    imshow(im_ave);
    title('����Ϊ3�ľ�ֵģ��');
    
    subplot(2,3,3);
    gaus_template = gaussian_template(3, 1.0);
    im_gaus = im_convolve(im_gray, gaus_template);
    imshow(im_gaus);
    title('����Ϊ3����׼��Ϊ1�ĸ�˹ģ��');
end


%% �ֲ�����
function out = clip(in, low, high)
    if in < low
        out = low;
    else if in > high
            out = high;
        else
            out = in;
        end
    end
end

%  ��ȡֱ��ͼ
function [hist] = imhist_t(im_gray)
    hist = zeros(256,1);
    [width, height] = size(im_gray);
    for x = 1 : width
        for y = 1 :height
            hist(im_gray(x, y) + 1) = hist(im_gray(x, y) + 1) + 1;
        end
    end
end

%   ���Ա任
function [im_out] = im_line_process(im_in, k, l)
    [width, height] = size(im_in);
    im_out = uint8(zeros(width, height));
    for x = 1 : width
        for y  = 1 : height
            pix_value = im_in(x,y) * k + l;
            im_out(x, y) = clip(pix_value, 0, 255);
        end
    end
end

%   ֱ��ͼ���滯
function [im_out, hist_out] = hist_norm(im_in, new_min, new_max)
    old_min = double(min(min(im_in)));
    old_max = double(max(max(im_in)));
    [width, height] = size(im_in);
    im_out = uint8(zeros(width, height));
    for x = 1 : width
        for y = 1 : height
            im_out(x, y) = (new_max - new_min) * (double(im_in(x, y)) - old_min) / (old_max - old_min) + new_min;
        end
    end
    hist_out = imhist_t(im_out);
end

%   ֱ��ͼ���⻯
function [im_out, hist_out] = hist_equa(im_in)
    [width, height] = size(im_in);
    im_out = uint8(zeros(width, height));
    lookup = uint8(zeros(256,1));
    hist = imhist_t(im_in);
    sum = 0;
    range = 255 - 0;
    total_num = width * height;
    
    for level = 1 : 256
        sum = sum + hist(level);
        lookup(level) = uint8(range * sum / total_num);
    end
    
    for x = 1 : width
        for y = 1 :height
            im_out(x, y) = lookup(im_in(x, y) + 1);
        end
    end
    hist_out = imhist_t(im_out);
end

%   �̶���ֵ���ж�ֵ��
function [im_out] = threshold_const(im_in, value)
    im_out = uint8(zeros(size(im_in)));
    im_out(im_in > value) = 255;
end

%   Otsu����������ֵ������
function [im_out] = threshold_otsu(im_in)
    hist = imhist_t(im_in);
    pix_num = numel(im_in);
    hist_rate = double(hist) ./ pix_num;
    w = zeros(256,1);
    u = zeros(256,1);
    level_max = find(hist_rate ~= 0, 1, 'last' );
    w(1) = hist_rate(1);
    u(1) = hist_rate(1) * 1;
    for level = 2 : level_max
        w(level) = w(level - 1) + hist_rate(level);
        u(level) = u(level - 1) + hist_rate(level) * level;
    end
    uT = u(level_max);
    tmp_value = (uT * w(1) - u(1))^2 / (w(1) * (1 - w(1)));
    threshold = 1;
    for level = 2 : level_max
        new_value = (uT * w(level) - u(level))^2 / (w(level) * (1 - w(level)));
        if new_value > tmp_value
            tmp_value = new_value;
            threshold = level;
        end
    end
    im_out = threshold_const(im_in, threshold);
end

%   ͼ���ģ����о������Ե���ֲ���
function [im_out] = im_convolve(im_in, template)
    [width, height] = size(template);
    im_out = im_in;
    pad_x = floor(width / 2);
    pad_y = floor(height / 2);
    for x = pad_x + 1 : width - pad_x
        for y = pad_y + 1 : height - pad_y
            im_out(x, y) = sum(sum(double(im_in(x - pad_x : x + pad_x, y - pad_y : y + pad_y)) .* template));
        end
    end
end

%   ����ƽ������ģ��
function [template] = average_template(win_size)
    value = 1 / (win_size * win_size);
    template(1:win_size, 1:win_size) = value;
end

%   ���ɸ�˹����ģ��
function [template] = gaussian_template(win_size, sigma)
     center = floor(win_size / 2) + 1;
     sum = 0;
     template  = zeros(win_size, win_size);
     for x = 1 : win_size
         for y = 1 : win_size
            template(x, y) = exp(- (((x - center) * (x - center) + (y - center) * (y - center)) / (2 * sigma * sigma)));
            sum = sum + template(x, y);
         end
     end
     template = template / sum;
end













