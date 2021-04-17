   1 #include <ros/ros.h>
   2 // PCL specific includes
   3 #include <pcl_conversions/pcl_conversions.h>
   4 #include <pcl/point_cloud.h>
   5 #include <pcl/point_types.h>
   6 
   7 #include <pcl/filters/voxel_grid.h>
   8 
   9 ros::Publisher pub;
  10 
  11    4 
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

  25 
  26 int
  27 main (int argc, char** argv)
  28 {
  29   // Initialize ROS
  30   ros::init (argc, argv, "my_pcl_tutorial");
  31   ros::NodeHandle nh;
  32 
  33   // Create a ROS subscriber for the input point cloud
  34   ros::Subscriber sub = nh.subscribe ("input", 1, cloud_cb);
  35 
  36   // Create a ROS publisher for the output point cloud
  37   pub = nh.advertise<pcl::PCLPointCloud2> ("output", 1);
  38 
  39   // Spin
  40   ros::spin ();
  41 }
