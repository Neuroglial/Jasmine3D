Scene: Scene Name
Environment:
  AssetPath: assets\env\birchwood_4k.hdr
  Light:
    Direction: [-0.788999975, 0.777999997, -0.782999992]
    Radiance: [1, 0.999989986, 0.999989986]
    Multiplier: 0.651000023
Entities:
  - Entity: 7669986082924618201
    TagComponent:
      Tag: Mesh
    TransformComponent:
      Position: [1.47547531, 2.63433456, 3.82678676]
      Rotation: [1, -2.64697796e-23, 2.98023224e-08, 8.8817842e-16]
      Scale: [9.31999207, 9.31999207, 9.31999397]
    MeshComponent:
      AssetPath: D:\Downloads\Compressed\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\JasEditor\assets\models\m1911\M1911Materials.fbx
  - Entity: 7475399290764333888
    TagComponent:
      Tag: Sphere
    TransformComponent:
      Position: [-1.3215456, 1.63065517, -7.27923393]
      Rotation: [1, 0, 0, 0]
      Scale: [2.6935997, 2.6935997, 2.6935997]
    MeshComponent:
      AssetPath: assets\meshes\Sphere1m.fbx
  - Entity: 11293686930003950360
    TagComponent:
      Tag: Scene
    TransformComponent:
      Position: [-1.8488706e-22, -1.74615455, -3.10189013e-15]
      Rotation: [1, 8.88205948e-16, 2.98023224e-08, -2.64706e-23]
      Scale: [13.0844994, 13.0844994, 13.0844994]
    MeshComponent:
      AssetPath: assets\meshes\CubeScene.fbx
  - Entity: 3370882484222092056
    TagComponent:
      Tag: Directional Light
    TransformComponent:
      Position: [0, 0, 0]
      Rotation: [0.716385961, 0.690598726, 0.0715050101, -0.0689316615]
      Scale: [0.99999541, 0.999995649, 0.999997437]
    DirectionalLightComponent:
      Radiance: [1, 1, 1]
      CastShadows: true
      SoftShadows: true
      LightSize: 0.5
  - Entity: 6605693014656896610
    TagComponent:
      Tag: Sky Light
    TransformComponent:
      Position: [0, 0, 0]
      Rotation: [1, 0, 0, 0]
      Scale: [1, 1, 1]
    SkyLightComponent:
      EnvironmentAssetPath: assets\env\birchwood_4k.hdr
      Intensity: 1
      Angle: 0