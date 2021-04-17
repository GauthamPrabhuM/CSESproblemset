#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;

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



int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2> ("input", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();
}
