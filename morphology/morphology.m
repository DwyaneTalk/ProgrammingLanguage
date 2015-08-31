function morphology()
    im = imread('lena_gray.jpg');
    im = threshold(im);
    template = ones(3) * 255;
    subplot(2,2,1);
    imshow(im);
    title('Ô­Ê¼Í¼Ïñ');
    subplot(2,2,2);
    im_erosion = erosion_binary(im, template);
    imshow(im_erosion);
    title('¸¯Ê´Í¼Ïñ');
    subplot(2,2,3);
    template = zeros(3, 3);
    im_dilation = dilation_binary(im, template);
    imshow(im_dilation);
    title('ÅòÕÍÍ¼Ïñ');
    subplot(2,2,4);
    imshow(im_dilation - im_erosion);
    title('²îÖµÍ¼Ïñ');
end

%% refer:http://blog.sina.com.cn/s/blog_6b205d630100sgk1.html

% ¸¯Ê´
function [im_out] = erosion_binary(im_in, template)
    if(find(im_in(im_in > 0) < 255))
        disp('´íÎó£¡·Ç¶þÖµÍ¼Ïñ');
    end
    [row, col] = size(im_in);
    [trow, tcol] = size(template);
    template = uint8(template);
    rhal = floor(trow / 2);
    chal = floor(tcol / 2);
    im_out = uint8(zeros(row - 2 * rhal, col - 2 * chal));
    for irow = 1 + rhal : row - rhal
        for icol = 1 + chal : col - chal
            im_diff = im_in(irow - rhal : irow + rhal, icol - chal : icol + chal) ~= template;
            if(any(im_diff(:)))
                im_out(irow, icol) = 0;
            else
                im_out(irow, icol) = 255;
            end
        end
    end
end

% ÅòÕÍ
function [im_out] = dilation_binary(im_in,template)
    if(find(im_in(im_in > 0) < 255))
        disp('´íÎó£¡·Ç¶þÖµÍ¼Ïñ');
    end
    [row, col] = size(im_in);
    [trow, tcol] = size(template);
    template = uint8(template);
    rhal = floor(trow / 2);
    chal = floor(tcol / 2);
    im_out = uint8(zeros(row - 2 * rhal, col - 2 * chal));
    for irow = 1 + rhal : row - rhal
        for icol = 1 + chal : col - chal
            im_diff = im_in(irow - rhal : irow + rhal, icol - chal : icol + chal) ~= template;
            if(any(im_diff(:)))
                im_out(irow, icol) = 255;
            else
                im_out(irow, icol) = 0;
            end
        end
    end
end