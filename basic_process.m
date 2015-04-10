%% 文件入口
function basic_process()
    clear;
    clc;
    im_rgb = imread('lena.jpg');
    im_gray = rgb2gray(im_rgb);
%% 图像表示
%   亮度直方图：统计图像在特定亮度级像素的数目，表示每个亮度级在图像中占的比例；
%   图像对比度：通过图像亮度范围来衡量像素亮度值的分散情况；
%   阈值处理：通过选择特定像素范围内的像素来选择图像中的目标，主要包括均一(固定)阈值处理和自适应阈值处理
% %% 点运算
%     figure(1);
%     subplot(5,2,1);
%     imshow(im_gray);
%     title('原始图像');
%     subplot(5,2,2);
%     hist_t = imhist_t(im_gray);
%     stem(0:255, hist_t, 'Marker', 'none');
%     title('原始直方图');
% %   点运算是通过计算原始图像像素点的函数值作为新图像对应位置像素值，从而实现图像直方图、对比度等变化
% %   常见点运算包括直方图处理（亮度正规化、直方图均衡化）、亮度映射（线型、非线性）和阈值处理等
%     subplot(5,2,3);
%     im_gray_line_process = im_line_process(im_gray, 1.2, 10);
%     imshow(im_gray_line_process);
%     title('线型点运算图像');
%     subplot(5,2,4);
%     hist_t = imhist_t(im_gray_line_process);
%     stem(0:255, hist_t, 'Marker', 'none');
%     title('线性点运算直方图');
% 
% %   直方图正规化：将直方图进行扩展和移位，使其涵盖所有256个灰度像素级
% %   实现：对每个像素点按照：Nx,y = (Nmax - Nmin) * (Ox,y - Omin) / (Omax - Omin) + Nmin 进行线型变换
% %   由于直方图正规化是线性变换，所以是可逆的，正规化后可以恢复原始图像和其直方图
%     [im_norm, hist_n] = hist_norm(im_gray, 0, 255);
%     subplot(5,2,5);
%     imshow(im_norm);
%     title('直方图正规化图像');
%     subplot(5,2,6);
%     stem(0:255, hist_n, 'Marker', 'none');
%     title('正规化直方图');
%     
% %   直方图均衡化：通过适合人眼的非线性变化来增强图像的对比度和亮度
% %   计算公式如下：将原q亮度级的像素变成Lookup(q)像素级，(Nmax - Nmin)/ N^2是假设将所有M*N个像素平均分到(Nmax
% %   - Nmin)个像素级，SUM(Hist(i))是原图像0-q像素级所有像素个数累加
% %   Lookup(q) = (Nmax - Nmin)/ (M*N) * SUM(Hist(i)) i=0……q
% %   Nx,y = Lookup(Ox,y)
% %   直方图均衡化的非线性变化，所以是不可逆的，不能够通过直方图均衡化后的图像恢复其原始图像
% %   图像经过线型点运算，不会改变直方图均衡化的结果，所以经过直方图正规化并不会改变直方图均衡化的结果
%     [im_equa, hist_e] = hist_equa(im_gray);
%     subplot(5,2,7);
%     imshow(im_equa);
%     title('直方图均衡化图像');
%     subplot(5,2,8);
%     stem(0:255, hist_e, 'Marker', 'none');
%     title('均衡化直方图');
%     
% %   阈值处理方法
%     im_thsd = threshold_const(im_gray, 160);
%     subplot(5,2,9);
%     imshow(im_thsd);
%     title('160阈值二值化图像');
%     im_otsu = threshold_otsu(im_gray);
%     subplot(5,2,10);
%     imshow(im_otsu);
%     title('Otsu方法阈值二值化图像')
% %% 群运算
% %   群运算是利用分组处理，利用像素周围的点通过卷积操作计算新的像素值。
% %   不同的群运算使用不同的卷积模版，卷积过程相当于滤波，所以不同的卷积模版会有不同的滤波效果
% %   对于原图像边缘处像素点，由于无法通过卷积计算获得新的像素值，所以可以按照下面方式处理（具体问题具体处理）：
% %       1、缩小图像，将边缘像素从新图像中去除，那么图像分辨率将变小；
% %       2、设为固定值（如边缘设为黑色0或白色255）；
% %       3、保持原始像素值；
% %       4、根据图像内部卷积得到的效新像素值，进行水平和竖直扩展
% %   常见的群运算有：均值滤波、高斯滤波、中值滤波、截断中值滤波、自适应加权中值滤波等
%     figure(2);
%     subplot(2,3,1);
%     imshow(im_gray);
%     title('原始图像');
%     
%     subplot(2,3,2);
%     im_noise = imnoise(im_gray, 'salt & pepper', 0.1);  %添加椒盐噪声
% %     im_noise = imnoise(im_noise, 'gaussian', 0, 0.01);%添加高斯白噪声
%     imshow(im_noise);
%     title('噪声图像');
%     
% %   均值滤波是通过低通滤波器，保留空间低频部分，抑制高频分量。
% %   所以均值滤波能够去除图像中的噪声，但是也会损失图像的细节，使图像变模糊
% %   均值滤波的模版窗口越大，效果越明显，窗口大小与低通滤波器的带宽反相关
%     subplot(2,3,3);
%     ave_template = average_template(5);                 %生成窗口为5的均值模版
%     im_ave = im_convolve(im_noise, ave_template);       %卷积滤波
%     imshow(im_ave);
%     title('均值滤波');
%     
% %   高斯滤波是通过二维高斯关系式（均值为0）确定高斯模版，然后进行卷积滤波
% %   高斯滤波相比均值滤波，是更优的图像平滑操作，能够更好地去除造成的同时保证了更好的细节保留，但是同样难以保留边界
% %   高斯滤波关系式的均值为0，所以通过不同的模版窗口大小和不同的方差大小确定高斯滤波的效果
%     subplot(2,3,4);
%     gaus_template = gaussian_template(3, 1);            %生成窗口3，标准差1的高斯模版
%     im_gaus = im_convolve(im_noise, gaus_template);     %卷积滤波
%     imshow(im_gaus);
%     title('高斯滤波');
%     
% %   中值滤波是用滤波窗口中所有像素的中值作为新的像素值
% %   中值滤波对于椒盐噪声有很好的效果，在抑制噪声的同时能保留图像的边界
% %   另外中值滤波还可以实现图像的旋转、找出连续图像中不变的背景部分，在去噪和保留细节方面也优于均值和高斯
%     subplot(2,3,5);
%     im_med = median_filter(im_noise, 3);                %窗口为3的中值滤波
%     imshow(im_med);
%     title('中值滤波');
%     
% %   截断中值滤波是根据窗口中像素的中值和均值的大小关系，确定窗口中有效像素值的范围，
% %       然后用窗口中像素值在有效像素范围内的像素点的中值作为新的像素值
% %   和中值滤波相比，截断中值滤波可以抑制滤波后的结果过亮或过暗，
% %       但是一般阶段一般要求更大的滤波窗口
%     subplot(2,3,6);
%     im_cut_med = cut_median_filter(im_noise, 3);        %窗口为3的截断中指滤波
%     imshow(im_cut_med);
%     title('截断中值滤波');

%% 数学形态学

    figure(3);

end


%% 局部函数
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

%  获取直方图
function [hist] = imhist_t(im_gray)
    hist = zeros(256,1);
    [row, col] = size(im_gray);
    for x = 1 : row
        for y = 1 :col
            hist(im_gray(x, y) + 1) = hist(im_gray(x, y) + 1) + 1;
        end
    end
end

%   线性变换
function [im_out] = im_line_process(im_in, k, l)
    [row, col] = size(im_in);
    im_out = uint8(zeros(row, col));
    for x = 1 : row
        for y  = 1 : col
            pix_value = im_in(x,y) * k + l;
            im_out(x, y) = clip(pix_value, 0, 255);
        end
    end
end

%   直方图正规化
function [im_out, hist_out] = hist_norm(im_in, new_min, new_max)
    old_min = double(min(min(im_in)));
    old_max = double(max(max(im_in)));
    [row, col] = size(im_in);
    im_out = uint8(zeros(row, col));
    for x = 1 : row
        for y = 1 : col
            im_out(x, y) = (new_max - new_min) * (double(im_in(x, y)) - old_min) / (old_max - old_min) + new_min;
        end
    end
    hist_out = imhist_t(im_out);
end

%   直方图均衡化
function [im_out, hist_out] = hist_equa(im_in)
    [row, col] = size(im_in);
    im_out = uint8(zeros(row, col));
    lookup = uint8(zeros(256,1));
    hist = imhist_t(im_in);
    sum = 0;
    range = 255 - 0;
    total_num = row * col;
    
    for level = 1 : 256
        sum = sum + hist(level);
        lookup(level) = uint8(range * sum / total_num);
    end
    
    for x = 1 : row
        for y = 1 :col
            im_out(x, y) = lookup(im_in(x, y) + 1);
        end
    end
    hist_out = imhist_t(im_out);
end

%   固定阈值进行二值化
function [im_out] = threshold_const(im_in, value)
    im_out = uint8(zeros(size(im_in)));
    im_out(im_in > value) = 255;
end

%   Otsu方法进行阈值化处理
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

%   图像和模版进行卷积，边缘保持不变
function [im_out] = im_convolve(im_in, template)
    [row, col] = size(template);
    im_out = im_in;
    pad_x = floor(row / 2);
    pad_y = floor(col / 2);
    for x = pad_x + 1 : row - pad_x
        for y = pad_y + 1 : col - pad_y
            im_out(x, y) = sum(sum(double(im_in(x - pad_x : x + pad_x, y - pad_y : y + pad_y)) .* template));
        end
    end
end

%   生成平均算子模版
function [template] = average_template(win_size)
    value = 1 / (win_size * win_size);
    template(1:win_size, 1:win_size) = value;
end

%   生成高斯算子模版
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

%   中值滤波
function [im_out] = median_filter(im_in, win_size)
    if ~mod(win_size, 2)
        return
    end
    [row, col] = size(im_in);
    pad = floor(win_size / 2);
    im_out = im_in;
    for x = 1 + pad : row - pad
        for y = 1 + pad : col - pad
%   对于3x3的窗口，求中指快速方法：http://www.cnblogs.com/BYTEMAN/archive/2012/07/21/2602181.html  
            im_win = im_in(x - pad : x + pad, y - pad : y + pad);
            im_out(x, y) = median(im_win(:));
        end
    end
end

%   截断中值滤波
function [im_out] = cut_median_filter(im_in, win_size)
    if ~mod(win_size,2)
        return;
    end
    [row, col] = size(im_in);
    im_out = im_in;
    pad = floor(win_size / 2);
    for x = 1 + pad : row - pad
        for y = 1 + pad : col - pad
            im_win = im_in(x - pad : x + pad, y - pad : y + pad);
            ave = mean(im_win(:));
            med = median(im_win(:));
            if ave > med
                cut_off = 2 * med - min(min(im_win));
            else if ave < med
                cut_off = 2 * med - max(max(im_win));
                end
            end
            count = 0;
            list = zeros(win_size * win_size);
            for i = 1 : win_size
                for j = 1 : win_size
                    if logical(ave > med) && logical(cut_off > im_win(i,j))
                        count = count + 1;
                        list(count) = im_win(i,j);  
                    end
                end
            end
            if count > 0
                im_out(x,y) = median(list(1 : count));
            else
                im_out(x,y) = med;
            end
        end
    end
end












