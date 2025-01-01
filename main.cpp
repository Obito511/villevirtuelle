#include "main.h"
#include "./ui_main.h"
#include <QApplication> // Include QApplication for the main function
#include <QPixmap>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DCore/QTransform>
#include <QMenuBar>

Qt3DCore::QEntity* createFuturisticScene(Qt3DCore::QEntity* rootEntity) {
    // Ground (green plane)
    Qt3DExtras::QPhongMaterial* groundMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    groundMaterial->setDiffuse(QColor(34, 139, 34)); // Green color

    Qt3DCore::QEntity* groundEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QPlaneMesh* groundMesh = new Qt3DExtras::QPlaneMesh();
    groundMesh->setWidth(50.0f);
    groundMesh->setHeight(50.0f);
    Qt3DCore::QTransform* groundTransform = new Qt3DCore::QTransform();
    groundTransform->setTranslation(QVector3D(0.0f, -1.0f, 0.0f));
    groundEntity->addComponent(groundMesh);
    groundEntity->addComponent(groundTransform);
    groundEntity->addComponent(groundMaterial);

    // House
    Qt3DCore::QEntity* houseEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QCuboidMesh* houseMesh = new Qt3DExtras::QCuboidMesh();
    houseMesh->setXExtent(3.0f);
    houseMesh->setYExtent(3.0f);
    houseMesh->setZExtent(3.0f);
    Qt3DCore::QTransform* houseTransform = new Qt3DCore::QTransform();
    houseTransform->setTranslation(QVector3D(-10.0f, 1.5f, 0.0f));
    Qt3DExtras::QPhongMaterial* houseMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    houseMaterial->setDiffuse(QColor(139, 69, 19)); // Brown color for the house
    houseEntity->addComponent(houseMesh);
    houseEntity->addComponent(houseTransform);
    houseEntity->addComponent(houseMaterial);

    // House Roof (triangular prism shape)
    Qt3DCore::QEntity* roofEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QCylinderMesh* roofMesh = new Qt3DExtras::QCylinderMesh();
    roofMesh->setRadius(2.0f);
    roofMesh->setLength(3.0f);
    roofMesh->setRings(4);
    roofMesh->setSlices(3); // Triangular prism shape
    Qt3DCore::QTransform* roofTransform = new Qt3DCore::QTransform();
    roofTransform->setTranslation(QVector3D(-10.0f, 4.0f, 0.0f));
    roofTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 1.0f), 90.0f));
    Qt3DExtras::QPhongMaterial* roofMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    roofMaterial->setDiffuse(QColor(165, 42, 42)); // Dark red for the roof
    roofEntity->addComponent(roofMesh);
    roofEntity->addComponent(roofTransform);
    roofEntity->addComponent(roofMaterial);

    // Factory
    Qt3DCore::QEntity* factoryEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QCuboidMesh* factoryMesh = new Qt3DExtras::QCuboidMesh();
    factoryMesh->setXExtent(6.0f);
    factoryMesh->setYExtent(4.0f);
    factoryMesh->setZExtent(4.0f);
    Qt3DCore::QTransform* factoryTransform = new Qt3DCore::QTransform();
    factoryTransform->setTranslation(QVector3D(10.0f, 2.0f, 0.0f));
    Qt3DExtras::QPhongMaterial* factoryMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    factoryMaterial->setDiffuse(QColor(128, 128, 128)); // Gray color for the factory
    factoryEntity->addComponent(factoryMesh);
    factoryEntity->addComponent(factoryTransform);
    factoryEntity->addComponent(factoryMaterial);

    // Factory Chimney
    Qt3DCore::QEntity* chimneyEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QCylinderMesh* chimneyMesh = new Qt3DExtras::QCylinderMesh();
    chimneyMesh->setRadius(0.5f);
    chimneyMesh->setLength(4.0f);
    Qt3DCore::QTransform* chimneyTransform = new Qt3DCore::QTransform();
    chimneyTransform->setTranslation(QVector3D(12.0f, 4.0f, 1.0f));
    Qt3DExtras::QPhongMaterial* chimneyMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    chimneyMaterial->setDiffuse(QColor(105, 105, 105)); // Dark gray for the chimney
    chimneyEntity->addComponent(chimneyMesh);
    chimneyEntity->addComponent(chimneyTransform);
    chimneyEntity->addComponent(chimneyMaterial);

    // Park (small plane)
    Qt3DCore::QEntity* parkEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QPlaneMesh* parkMesh = new Qt3DExtras::QPlaneMesh();
    parkMesh->setWidth(5.0f);
    parkMesh->setHeight(5.0f);
    Qt3DCore::QTransform* parkTransform = new Qt3DCore::QTransform();
    parkTransform->setTranslation(QVector3D(0.0f, -0.9f, -10.0f));
    Qt3DExtras::QPhongMaterial* parkMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
    parkMaterial->setDiffuse(QColor(34, 139, 34)); // Same green color as the ground
    parkEntity->addComponent(parkMesh);
    parkEntity->addComponent(parkTransform);
    parkEntity->addComponent(parkMaterial);

    // Park Trees
    for (int i = 0; i < 3; ++i) {
        Qt3DCore::QEntity* treeTrunk = new Qt3DCore::QEntity(rootEntity);
        Qt3DExtras::QCylinderMesh* trunkMesh = new Qt3DExtras::QCylinderMesh();
        trunkMesh->setRadius(0.2f);
        trunkMesh->setLength(1.0f);
        Qt3DCore::QTransform* trunkTransform = new Qt3DCore::QTransform();
        trunkTransform->setTranslation(QVector3D(-2.0f + i * 2.0f, -0.4f, -10.5f));
        Qt3DExtras::QPhongMaterial* trunkMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
        trunkMaterial->setDiffuse(QColor(139, 69, 19));
        treeTrunk->addComponent(trunkMesh);
        treeTrunk->addComponent(trunkTransform);
        treeTrunk->addComponent(trunkMaterial);

        Qt3DCore::QEntity* treeCanopy = new Qt3DCore::QEntity(rootEntity);
        Qt3DExtras::QSphereMesh* canopyMesh = new Qt3DExtras::QSphereMesh();
        canopyMesh->setRadius(0.5f);
        Qt3DCore::QTransform* canopyTransform = new Qt3DCore::QTransform();
        canopyTransform->setTranslation(QVector3D(-2.0f + i * 2.0f, 0.1f, -10.5f));
        Qt3DExtras::QPhongMaterial* canopyMaterial = new Qt3DExtras::QPhongMaterial(rootEntity);
        canopyMaterial->setDiffuse(QColor(34, 139, 34));
        treeCanopy->addComponent(canopyMesh);
        treeCanopy->addComponent(canopyTransform);
        treeCanopy->addComponent(canopyMaterial);


    }


    return rootEntity;
}


//constructeur
Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main)
{

    ui->setupUi(this);


}

Main::~Main()
{
    delete ui;
}

// Entry point for the application
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a 3D window
    Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(20, 20, 40));

    // Root entity
    Qt3DCore::QEntity* rootEntity = new Qt3DCore::QEntity();

    // Camera setup
    Qt3DRender::QCamera* camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(20.0f, 15.0f, 30.0f));
    camera->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));

    // Camera controls
    Qt3DExtras::QOrbitCameraController* camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    QMainWindow mainWindow;
    QWidget* container = QWidget::createWindowContainer(view);
    mainWindow.setCentralWidget(container);

    // Menu bar
    QMenuBar* menuBar = mainWindow.menuBar();
    QMenu* cityMenu = menuBar->addMenu("Manage City");

    QAction* addBuildingAction = new QAction("Add Building", &mainWindow);
    QAction* deleteBuildingAction = new QAction("Delete Building", &mainWindow);
    QAction* updateBuildingAction = new QAction("Update Building", &mainWindow);

    cityMenu->addAction(addBuildingAction);
    cityMenu->addAction(deleteBuildingAction);
    cityMenu->addAction(updateBuildingAction);
    // Create the futuristic scene
    createFuturisticScene(rootEntity);

    // Set root entity
    view->setRootEntity(rootEntity);

    // Show the window
    view->show();
 mainWindow.resize(1024, 768);
    mainWindow.show();
    return app.exec();
}
