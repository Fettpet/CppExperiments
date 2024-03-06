# Nested Loader

Our goal is to inject a topbar into a component. This requires loading the topbar with a loader. If the entire component is itself in a loader, we have a nested loader structure. Here is an example of the corresponding QML code:

```qml
Item {    
  id: root    
  property Component component    
  property bool active: true    
  Loader {        
    active: root.active        
    sourceComponent: Component {            
      Loader {                
        sourceComponent: root.component                
        anchors.fill: parent                
        onLoaded: console.log("Loaded inside")            
      }        
    }        
    onLoaded: console.log("Loaded outside")        
    anchors.fill: parent    
  }
}
```

## Discussion

### If the outer loader is deactivated, is the inner loader also deactivated?

Yes, both are deactivated.

### If the outer loader is activated, is the inner loader also activated?

The inner loader is only activated if it is also active.

### How can a component object be injected?

The component can simply be set. Here is an example:

```qml
View {
    id: view
    component: inline_comp

    Component {
        id: inline_comp
        Rectangle {
            color: "red"
            anchors.fill: parent
            Text {
                anchors.centerIn: parent
                text: qsTr("Inline Component")
            }
        }
    }
}
```

Question: How can a component file be injected?

The file is loaded in a loader. This loader is inside a component. The component can then be passed on. Here is an example:

```qml
View {
    id: view
    component: file_comp
 
    Component {        
        id: file_comp        
        Loader {            
            source: "MyRect.qml"            
            onLoaded: console.log("Load file MyRect.qml")        
        }    
    }
}
```
