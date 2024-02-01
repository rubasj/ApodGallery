import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import ApodGallery

ApplicationWindow {
    width: 600
    height: 800
    visible: true
    title: qsTr("NASA APOD Gallery")

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
                icon.source: "qrc:/ApodGallery/app_icons/settings.png"
                onClicked: settingsMenu.open()
                Menu {
                    id: settingsMenu
                    y:mainToolBar.height

                    MenuItem {
                        text: qsTr("Load image")
                        onTriggered: {
                            loadDialog.open()
                        }

                    }

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

                            testImg.logMessage(model.name)
                        }
                        anchors.fill: parent
                    }
                }

                spacing: 5

                Label {
                    text: model.name
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.bold: imgSelector.currentIndex == index
                }
            }
        }
    }


    Image {
        id: mainImg
        property real zoom: 0.0
        property real zoomStep: 0.1

        asynchronous: true
        cache: false
        smooth: true
        antialiasing: true
        mipmap: true
        anchors.fill: parent
        anchors.margins: 20
        fillMode: Image.PreserveAspectFit
        source: images[imgSelector.currentIndex].url
    }

    PinchArea {
        pinch.target: mainImg
        anchors.fill: parent
        pinch.minimumScale: 0.1
        pinch.maximumScale: 4
    }
    // Mouse zoom
    MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.NoButton
            wheel: enabled

            onWheel: {
                if (wheel.angleDelta.y > 0)
                    mainImg.zoom = Number((mainImg.zoom + mainImg.zoomStep).toFixed(1))
                else
                    if (mainImg.zoom > 0) mainImg.zoom = Number((mainImg.zoom - mainImg.zoomStep).toFixed(1))

                wheel.accepted=true
            }
    }


}
