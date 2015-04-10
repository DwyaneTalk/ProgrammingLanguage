function edgeDetection2()
    clear all;
    close all;
    clc;
    im_gray = imread('person.jpg');
    figure(2);
    
    subplot(1,3,1);
    imshow(im_gray);
    title('原始图像');
    
    im_gaus = imfilter(im_gray, fspecial('gaussian', [5 5], 0.2));
    
    subplot(1,3,2);
    H1 = [0 -1 0; -1 4 -1; 0 -1 0];
    im_laplacian_H1 = imfilter(im_gaus, H1, 'replicate');
    imshow(im_laplacian_H1);
    title('LoG算子进行检测');
    
    subplot(1, 3, 3);
    MH_m = Marr_Hildreth(5, 1)
    im_laplacian_H2 = imfilter(im_gray, MH_m, 'replicate');
    imshow(im_laplacian_H2);
    title('Marr-Hildreth算子进行检测');
end

function MH_m = Marr_Hildreth(win_size, sigma)
    mid = floor(win_size / 2 + 1);
    MH_m = zeros(win_size, win_size);
    for i = 1 : win_size
        for j = 1 : win_size
            x = i - mid;
            y = j - mid;
            x2y2 = x * x + y * y;
            sigma2 = sigma * sigma;
            MH_m(i,j)= ((x2y2 - 2 * sigma2) * exp(-x2y2/(2 * sigma2))) / (sigma2 * sigma2); 
        end
    end
end