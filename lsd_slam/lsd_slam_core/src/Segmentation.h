#ifndef SEGMENTATION_H_
#define SEGMENTATION_H_

#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/features/integral_image_normal.h>
#include <pcl/filters/voxel_grid.h>

#include <boost/thread/thread.hpp>

#include "MainPlane.h"
#include "osg_gui.h"
#include "Plane.h"

class Segmentation
{

public:

    Segmentation ();
    ~Segmentation();

    bool passthroughFilter(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max,  pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &out_cloud);
    bool findGround(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud, MainPlane &mp);
    bool normalDifferenceError(pcl::ModelCoefficients::Ptr &normal, double error);
    bool normalDifferenceError2(pcl::ModelCoefficients::Ptr &normal, double error);

    int  findOtherPlanesRansac(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud,Eigen::Vector3f axis, std::vector <pcl::ModelCoefficients> &coeffPlanes, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &vectorCloudInliers, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &vectorHull );
    int regionGrowing(std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &inliers, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &clusters);
    void regionGrowing2( pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  &cloud, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  &outliers, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &clusters);
    void statisticalRemovalOutliers(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud);
    void removeWall(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud);
    void doSegmentation(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud);
    void createPlane(std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &clusters);

    bool getIsComputed() const;
    void getPlanes(std::vector<Plane> &planes) ;
    void getMainCloud(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud);
    void computeTransformation();
    void computeHeight();
    void euclidianClustering( pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  &cloud, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &clusters);
    void ransac(std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &clusters, Eigen::Vector3f axis, std::vector < pcl::PointCloud<pcl::PointXYZRGBA>::Ptr > &vectorCloudInliers,pcl::PointCloud<pcl::PointXYZRGBA>::Ptr  &outliers );
    void transformOrigin();
    MainPlane getMainPlane() const;
private:

    float _coeffRansac;
    MainPlane _ground;
    bool isComputed;
    std::vector<Plane> _planes;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _mainCloud;
    Eigen::Matrix4f transformXY;
    Eigen::Matrix4f transformTranslationOrigin;
    std::vector<pcl::ModelCoefficients::Ptr> _vectorNormalPlanes;
    Eigen::Vector3f _axis;

    bool _first;
};
#endif
