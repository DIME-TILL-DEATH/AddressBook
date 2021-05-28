import QtQuick 2.0
import QtGraphicalEffects 1.0

Image {
    id: root
    property bool rounded: true

    layer.enabled: rounded
    layer.effect: OpacityMask{
        maskSource: Item{
            width: root.width
            height: root.height
            // make circle mask
            Rectangle{
                anchors.centerIn: parent
                width: root.width
                height: root.height
                radius: Math.min(height, width) / 2
            }
        }
    }
}
