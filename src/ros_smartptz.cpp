#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


/**
 * @brief imageCallback callback triggered by topic <myImageTopic>
 * @param image_msg the image message
 */

void imageCallback(const sensor_msgs::ImageConstPtr& image_msg)
{

}

int main(int argc, char **argv)
{
    /* Initialize ros objects */
    ros::init(argc, argv, "smart_ptz");
    ros::NodeHandle nh;


    /* Create publisher and subscribers */
    image_transport::ImageTransport it(nh);
    topic_name = "/camera/rgb/image_raw";
    image_transport::Subscriber sub = it.subscribe(topic_name, 1, imageCallback);
    featextr_pub = nh.advertise<std_msgs::String>("coords",1);

    /* Spin ! */
    ros::spin();

}
