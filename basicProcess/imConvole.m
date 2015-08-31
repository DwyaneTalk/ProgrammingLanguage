function [im_out] = imConvole(im_in, template)
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