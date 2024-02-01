import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import ApodGallery

ApplicationWindow {
    width: 600
    height: 800
    visible: true
    title: qsTr("Picture Gallery")

    header: ToolBar {
        id: mainToolBar
        RowLayout {
            anchors.fill: parent

            ToolButton {
                icon.source: "qrc:/ApodGallery/app_icons/menu.png"
                onClicked: leftPane.open()
            }
            Label {
                text: qsTr("Picture galery")
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignCenter
                font.pointSize: 15
            }

            ToolButton {
                id: favBtn
                icon.source: images[imgSelector.currentIndex].favourite ? "qrc:/ApodGallery/app_icons/favourite.png" : "qrc:/ApodGallery/app_icons/favourite_unfilled.png"
                onClicked: {
                        // Toggle the favourite attribute for the current image
                        images[imgSelector.currentIndex].favourite = !images[imgSelector.currentIndex].favourite;
                        // Update the source of the button's image
                        favBtn.icon.source = images[imgSelector.currentIndex].favourite ? "qrc:/ApodGallery/app_icons/favourite.png" : "qrc:/ApodGallery/app_icons/favourite_unfilled.png";
                    }
            }

            ToolButton {
                icon.source: "qrc:/ApodGallery/app_icons/rotate_rigth.png"
                onClicked: {
                    mainImg.rotation += 90;
                }
            }
            ToolButton {
                icon.source: "qrc:/ApodGallery/app_icons/rotate_left.png"
                onClicked: {
                    mainImg.rotation -= 90;
                }
            }

            ToolButton {
                icon.source: "qrc:/ApodGallery/app_icons/settings.png"
                onClicked: settingsMenu.open()
                Menu {
                    id: settingsMenu
                    y:mainToolBar.height

                    MenuItem {
                        text: qsTr("Quit")
                        onTriggered: Qt.quit()
                    }
                }
            }
        }
    }

    Drawer {
        id: leftPane
        y:mainToolBar.height
        height: parent.height - mainToolBar.height
        width: parent.width * 0.4

        ListView {
            id: imgSelector
            spacing: 20
            anchors.fill: parent
            anchors.margins: 20
            model: images
            delegate: Column {

                width: parent.width

                Image {
                    source: model.url
                    width: parent.width
                    fillMode: Image.PreserveAspectFit

                    MouseArea {
                        onClicked:{
                            leftPane.close()
                            imgSelector.currentIndex = index
                            favBtn.icon.source = images[imgSelector.currentIndex].favourite ? "qrc:/ApodGallery/app_icons/favourite.png" : "qrc:/ApodGallery/app_icons/favourite_unfilled.png";

                        }
                        anchors.fill: parent
                    }
                }

                spacing: 5
                Label {
                    text: model.name
                    Layout.fillWidth: true
                    horizontalAlignment: Qt.AlignLeft
                    font.bold: imgSelector.currentIndex === index
                }

            }
        }
    }

    Image {
        id: mainImg
        property real zoom: 1.0
        property real zoomStep: 0.1
        property real mouseX: 0
        property real mouseY: 0
        property point dragStartPosition: Qt.point(0, 0) // Initialize dragStartPosition
        property point dragLastPosition: Qt.point(0, 0)  // Initialize dragLastPosition
        property real rotation: 0

        asynchronous: true
        cache: false
        smooth: true
        antialiasing: true
        mipmap: true
        anchors.fill: parent
        anchors.margins: 20
        fillMode: Image.PreserveAspectFit
        source: images[imgSelector.currentIndex].url

        transform: [
            Rotation {
                origin.x: mainImg.width / 2;
                origin.y: mainImg.height / 2;
                angle: mainImg.rotation
            },
            Scale {
            origin.x: mainImg.width / 2
            origin.y: mainImg.height / 2
            xScale: mainImg.zoom
            yScale: mainImg.zoom
        },
        Translate {
            x: mainImg.mouseX
            y: mainImg.mouseY
        }]
    }

    PinchArea {
        pinch.target: mainImg
        anchors.fill: parent
        pinch.minimumScale: 0.1
        pinch.maximumScale: 4
    }

    // Mouse wheel zoom
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.NoButton

        onWheel: {
            if (wheel.angleDelta.y > 0)
                mainImg.zoom = Number((mainImg.zoom + mainImg.zoomStep).toFixed(1))
            else
                if (mainImg.zoom > 0) mainImg.zoom = Number((mainImg.zoom - mainImg.zoomStep).toFixed(1))

            wheel.accepted=true
        }
    }

    // Mouse positioner
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton

        onPressed: {
            mainImg.dragStartPosition = Qt.point(mouse.x, mouse.y)
            mainImg.dragLastPosition = Qt.point(mainImg.mouseX, mainImg.mouseY)
        }

        onPositionChanged: {
            if (mouse.buttons & Qt.LeftButton) {
                mainImg.mouseX = mainImg.dragLastPosition.x + mouse.x - mainImg.dragStartPosition.x
                mainImg.mouseY = mainImg.dragLastPosition.y + mouse.y - mainImg.dragStartPosition.y
            }
        }
    }
}
