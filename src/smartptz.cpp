#include "ros/ros.h"
#include "std_msgs/String.h"

#include <stdio.h>
#include <sstream>


/**
 * @brief imageCallback callback triggered by topic <myImageTopic>
 * @param image_msg the image message
 */

void imageCallback(const std_msgs::String::ConstPtr& image_msg)
{

}

int main(int argc, char **argv)
{
    /* Initialize ros objects */
    ros::init(argc, argv, "smart_ptz");
    ros::NodeHandle mynode;


    /* Create publisher and subscribers */
    //subscriber
    std::string topic_name = "/camera/rgb/image_raw";
    ros::Subscriber sub = mynode.subscribe(topic_name, 1, imageCallback);
    //publisher
    ros::Publisher mypublisher = mynode.advertise<std_msgs::String>("coords",1);

    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " ;



    msg.data = ss.str();

    mypublisher.publish(msg);


    //loop ros
    ros::Rate loop_rate(10);2

    while(ros::ok())
    {
        ROS_INFO("Coucou!\n");
        std::printf("Yeah\n");
    /* Spin ! */
    ros::spinOnce();

    loop_rate.sleep();

    }

}
