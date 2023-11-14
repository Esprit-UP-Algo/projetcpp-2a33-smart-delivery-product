import QtQuick 2.0
import QtLocation 5.9
import QtPositioning 5.9
Rectangle {
    id:window

    property double latitude: 36.8065
    property double longitude:10.1815

    property  Component locationmarker: locmarker
    Plugin
    {
        id:googlemapview
        name:"osm"

    }
    Map
    {
        id:mapview
        anchors.fill: parent
        plugin: googlemapview
        center: QtPositioning.coordinate(latitude,longitude)
        zoomLevel: 9
       }
    function setCenterPosition(lati , longi)
    {
        mapview.pan(latitude - lati , longitude - longi)
        lati = lati
        longitude = longi
    }
    function setLocationMarking(lati , longi)
    {
        var item = locationmarker.createObject(window,{
                                                  coordinate:QtPositioning.coordinate(lati,longi)
                                              })
        mapview.addMapItem(item)

    }
    Component
    {
        id:locmarker
        MapQuickItem
        {
            id:markerImg
            anchorPoint.x:image.width/4
             anchorPoint.y:image.height
             coordinate: position
             sourceItem: Image {
                 id: image
                 width: 20
                 height: 20
                 source: "https://www.pngarts.com/files/3/Map-Marker-Pin-PNG-Image-Background.png"
             }
        }

    }


}
