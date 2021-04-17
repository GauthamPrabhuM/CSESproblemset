   1 #include <ros/ros.h>
   2 // PCL specific includes
   3 #include <sensor_msgs/PointCloud2.h>
   4 #include <pcl_conversions/pcl_conversions.h>
   5 #include <pcl/point_cloud.h>
   6 #include <pcl/point_types.h>
   7 
   8 ros::Publisher pub;
   9 
  10 void 
  11 cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
  12 {
  13   // Create a container for the data.
  14   sensor_msgs::PointCloud2 output;
  15 
  16   // Do data processing here...
  17   output = *input;
  18 
  19   // Publish the data.
  20   pub.publish (output);
  21 }
  22 
  23 int
  24 main (int argc, char** argv)
  25 {
  26   // Initialize ROS
  27   ros::init (argc, argv, "my_pcl_tutorial");
  28   ros::NodeHandle nh;
  29 
  30   // Create a ROS subscriber for the input point cloud
  31   ros::Subscriber sub = nh.subscribe ("input", 1, cloud_cb);
  32 
  33   // Create a ROS publisher for the output point cloud
  34   pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
  35 
  36   // Spin
  37   ros::spin ();
  38 }
