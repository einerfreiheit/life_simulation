/*
 * VisualWorker.cpp
 *
 *  Created on: 21 февр. 2017 г.
 *      Author: lenovo
 */

#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>

VisualWorker::VisualWorker()
{
    this->name = "VisualWorker";

}
void VisualWorker::work(World *world)
{
    getImageNICE(world);
    showImage(world);


}

void VisualWorker::showImage(World *world)
{
    cv::namedWindow("123", CV_WINDOW_NORMAL);
    cv::resizeWindow("123", 300, 300);
    cv::imshow("123", world->matrix);
    cv::waitKey(10);


}

void VisualWorker::getImage(World *world)
{
    worm_map = (world->worm_map); //@ тут везде скобки лишние
    map = (world->map);//@ они ничего полезного не делают
    mapHeight = (world->mapHeight); //@ если ты думаешь, что они тут для чего-то нужны, то тебе надо это переосмыслить
    mapWidth = (world->mapWidth);

    //@ вообще ты на каждом шаге берёшь и перекопируешь все данные из World'а в этого воркера.
    //@ а если карта большая, или червей много?
    //@ это неоптимально и выглядит очень странно

    //@ если ты не хочешь плодить графоманию вида world->worm_map везде, ты можешь просто в начале метода написать
    //@ std::vector<worm> &worm_map = world->worm_map; - объявление переменной-ссылки, оно не перекопирует данные из объекта в правой части
    //@ аналогично сокращается графомания с другими переменными


    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int color_delta;
            if (map[y][x].life_res >= 100) {
                color_delta = 255;
            } else
                color_delta = map[y][x].life_res * 255 / 100;
            world->matrix.at<cv::Vec3b>(cv::Point(y, x))[1] = 255 - color_delta;
            world->matrix.at<cv::Vec3b>(cv::Point(y, x))[2] = 255 - color_delta;
            world->matrix.at<cv::Vec3b>(cv::Point(y, x))[0] = 255; //@ и при этом ты каждый раз пишешь world->matrix и графоманишь

        }
    }
    for (int i = 0; i < world->worm_map.size(); i++) {
        //@ каждый раз при обращении к одному и тому же пикселю картинки ты создаёшь новый объект cv::Point
        //@ это первый грех, его можно исправить, объявив один раз этот cv::Point в начале:
        //@ cv::Point pos(worm_map[i].worm_y, worm_map[i].worm_x); - а потом везде подставлять этот pos
        //@ второй грех - ты каждый раз обращаешься к цв матрице и просишь её найти пиксель по таким-то координатам
        //@ графоманию в твоём случае можно было бы сократить вот так:
        //@ cv::Vec3b &pixel = world->matrix.at<cv::Vec3b>(.......
        //@ pixel[2] = 255;  и т.д.
        world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
            255;
        world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[0] =
            0;
        world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[1] =
            0;
        //@ и для дальнейшего сокращения графомании worm &worm
        if (worm_map[i].worm_hungry == true) {
            world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
                0;
        }

    }

}

void VisualWorker::getImageNICE(World *world)
{   
    cv::Mat visual = world->matrix;
    
    for (int y = world->getHeight()-1; y >= 0 ; y--) {
        for (int x = world->getWidth() - 1; x >= 0; x--) {
            double life_res = world->map[y][x].life_res;
            int color_delta = std::min(255.0, life_res * 255.0 / 100.0); 
            cv::Vec3b &pixel = visual.at<cv::Vec3b>(y, x);
            pixel[1] = 255 - color_delta;
            pixel[2] = 255 - color_delta;
            pixel[0] = 255;
        }
    }
    for (auto &currentWorm : world->worm_map){//@ это называется range-based for loop
        //@ ключевое слово auto тоже хорошо, но не стоит им злоупотреблять
        //@ и плохо то, что ты классы все назвал с маленькой буквы изначально. Надо будет исправить.Так никто не делает.
        //@ если бы был класс Worm с большой буквы, я мог бы объявлять переменные так:
        //@ Worm worm;
        //@ а из-за мелкобуквенности не могу, в том числе в цикле переменная у меня поэтому currentWorm, а не просто worm
        cv::Vec3b &pixel = visual.at<cv::Vec3b>(currentWorm.worm_y, currentWorm.worm_x);
        pixel[2] = currentWorm.worm_hungry ? 0 : 255;//@ а это тернарный оператор сравнения и присвоения, он по-своему коварен, но позволяет иногда избежать графомании
        pixel[0] = 0;
        pixel[1] = 0;
    }
}

VisualWorker::~VisualWorker()
{
    // TODO Auto-generated destructor stub
}

