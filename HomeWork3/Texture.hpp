//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        //Bilinear Interpolation
        if(u_img < 0)
            u_img = 0;
        if(v_img  < 0)
           v_img = 0;

        int uFloor = u_img;
        int uCelling = u_img + 1 > width ? width: u_img + 1;
        int vFloor = v_img;
        int vCelling = v_img + 1 > height ? height: v_img + 1;
        

        auto color00 = image_data.at<cv::Vec3b>(vFloor, uFloor);
        auto color01 = image_data.at<cv::Vec3b>(vCelling, uFloor);
        auto color10 = image_data.at<cv::Vec3b>(vFloor, uCelling);
        auto color11 = image_data.at<cv::Vec3b>(vCelling, uCelling);

        auto colorMix1 = color00 + (u_img - uFloor) * (color01 - color00);
        auto colorMix2 = color10 + (u_img - uFloor) * (color11 - color10);
        auto color = colorMix1 + (v_img - vFloor) * (colorMix2 - colorMix1);
        
      //  auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

};
#endif //RASTERIZER_TEXTURE_H
