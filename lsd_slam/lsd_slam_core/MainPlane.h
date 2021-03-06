
#include <pcl/filters/extract_indices.h>
#include <pcl/surface/convex_hull.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/surface/concave_hull.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>

class MainPlane
{
public:
    MainPlane();
    ~MainPlane();
    void clear();
    void setCoefficients(pcl::ModelCoefficients::Ptr &coeff);
    void setIndices(pcl::PointIndices::Ptr &ind);
    void setPlaneCloud(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud);
    void setHull(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &hull);
    pcl::ModelCoefficients::Ptr getCoefficients() const;
    pcl::PointIndices::Ptr getIndices() const;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  getPlaneCloud() const;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  getHull() const;
private:

    pcl::ModelCoefficients::Ptr coefficients;
    pcl::PointIndices::Ptr indices;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr planeCloud;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _hull;


};
