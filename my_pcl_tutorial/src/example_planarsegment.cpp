   1 #include <ros/ros.h>
   2 // PCL specific includes
   3 #include <sensor_msgs/PointCloud2.h>
   4 #include <pcl_conversions/pcl_conversions.h>
   5 #include <pcl/ros/conversions.h>
   6 #include <pcl/point_cloud.h>
   7 #include <pcl/point_types.h>
   8 
   9 #include <pcl/sample_consensus/model_types.h>
  10 #include <pcl/sample_consensus/method_types.h>
  11 #include <pcl/segmentation/sac_segmentation.h>
  12 
  13 ros::Publisher pub;
  14 
   4 
   5 void 
   6 cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
   7 {
   8   // Container for original & filtered data
   9   pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2; 
  10   pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
  11   pcl::PCLPointCloud2 cloud_filtered;
  12 
  13   // Convert to PCL data type
  14   pcl_conversions::toPCL(*cloud_msg, *cloud);
  15 
  16   // Perform the actual filtering
  17   pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  18   sor.setInputCloud (cloudPtr);
  19   sor.setLeafSize (0.1, 0.1, 0.1);
  20   sor.filter (cloud_filtered);
  21 
  22   // Convert to ROS data type
  23   sensor_msgs::PointCloud2 output;
  24   pcl_conversions::fromPCL(cloud_filtered, output);
  25 
  26   // Publish the data
  27   pub.publish (output);
  28 }

  41 
  42 int
  43 main (int argc, char** argv)
  44 {
  45   // Initialize ROS
  46   ros::init (argc, argv, "my_pcl_tutorial");
  47   ros::NodeHandle nh;
  48 
  49   // Create a ROS subscriber for the input point cloud
  50   ros::Subscriber sub = nh.subscribe ("input", 1, cloud_cb);
  51 
  52   // Create a ROS publisher for the output model coefficients
  53   pub = nh.advertise<pcl_msgs::ModelCoefficients> ("output", 1);
  54 
  55   // Spin
  56   ros::spin ();
  57 }














