clear;
clc;
addpath(genpath(pwd));
im_gray = imread('lena_gray.jpg');
if(ndims(im_gray) == 3)
    im_gray = rgb2gray(im_gray);
end
%% 数学形态学
%     figure(3);

%% 图像表示
%   亮度直方图：统计图像在特定亮度级像素的数目，表示每个亮度级在图像中占的比例；
%   图像对比度：通过图像亮度范围来衡量像素亮度值的分散情况；
%   阈值处理：通过选择特定像素范围内的像素来选择图像中的目标，主要包括均一(固定)阈值处理和自适应阈值处理
%% 点运算
%     figure(1);
%     subplot(5,2,1);
%     imshow(im_gray);
%     title('原始图像');
%     subplot(5,2,2);
%     hist_t = imHist(im_gray);
%     stem(0:255, hist_t, 'Marker', 'none');
%     title('原始直方图');
% %   点运算是通过计算原始图像像素点的函数值作为新图像对应位置像素值，从而实现图像直方图、对比度等变化
% %   常见点运算包括直方图处理（亮度正规化、直方图均衡化）、亮度映射（线型、非线性）和阈值处理等
%     subplot(5,2,3);
%     im_gray_line_process = lineProcess(im_gray, 1.2, 10);
%     imshow(im_gray_line_process);
%     title('线型点运算图像');
%     subplot(5,2,4);
%     hist_t = imHist(im_gray_line_process);
%     stem(0:255, hist_t, 'Marker', 'none');
%     title('线性点运算直方图');
% % 
% %   直方图正规化：将直方图进行扩展和移位，使其涵盖所有256个灰度像素级
% %   实现：对每个像素点按照：Nx,y = (Nmax - Nmin) * (Ox,y - Omin) / (Omax - Omin) + Nmin 进行线型变换
% %   由于直方图正规化是线性变换，所以是可逆的，正规化后可以恢复原始图像和其直方图
%     [im_norm, hist_n] = histOperation(im_gray, 0, 255);
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
%     [im_equa, hist_e] = histOperation(im_gray);
%     subplot(5,2,7);
%     imshow(im_equa);
%     title('直方图均衡化图像');
%     subplot(5,2,8);
%     stem(0:255, hist_e, 'Marker', 'none');
%     title('均衡化直方图');
% %     
% %   阈值处理方法
%     im_thsd = threshold(im_gray, 100);
%     subplot(5,2,9);
%     imshow(im_thsd);
%     title('160阈值二值化图像');
%     im_otsu = threshold(im_gray);
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
%     im_ave = imFilter('AVERAGE', im_noise, 5);       %卷积滤波
%     imshow(im_ave);
%     title('均值滤波');
%     
% %   高斯滤波是通过二维高斯关系式（均值为0）确定高斯模版，然后进行卷积滤波
% %   高斯滤波相比均值滤波，是更优的图像平滑操作，能够更好地去除造成的同时保证了更好的细节保留，但是同样难以保留边界
% %   高斯滤波关系式的均值为0，所以通过不同的模版窗口大小和不同的方差大小确定高斯滤波的效果
%     subplot(2,3,4);
%     im_gaus = imFilter('GAUSSIAN', im_noise, 3, 1);     %卷积滤波
%     imshow(im_gaus);
%     title('高斯滤波');
%     
% %   中值滤波是用滤波窗口中所有像素的中值作为新的像素值
% %   中值滤波对于椒盐噪声有很好的效果，在抑制噪声的同时能保留图像的边界
% %   另外中值滤波还可以实现图像的旋转、找出连续图像中不变的背景部分，在去噪和保留细节方面也优于均值和高斯
%     subplot(2,3,5);
%     im_med = imFilter('MEDIAN', im_noise, 3);                %窗口为3的中值滤波
%     imshow(im_med);
%     title('中值滤波');
%     
% %   截断中值滤波是根据窗口中像素的中值和均值的大小关系，确定窗口中有效像素值的范围，
% %       然后用窗口中像素值在有效像素范围内的像素点的中值作为新的像素值
% %   和中值滤波相比，截断中值滤波可以抑制滤波后的结果过亮或过暗，
% %       但是一般阶段一般要求更大的滤波窗口
%     subplot(2,3,6);
%     im_cut_med = imFilter('CUT_MEDIAN', im_noise, 3);        %窗口为3的截断中指滤波
%     imshow(im_cut_med);
%     title('截断中值滤波');

pause();
close all;
