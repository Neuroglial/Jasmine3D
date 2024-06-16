Scene: Scene Name
Environment:
  AssetPath: D:\Downloads\Compressed\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\JasEditor\assets\env\pink_sunrise_4k.hdr
  Light:
    Direction: [-0.787, -0.73299998, 1]
    Radiance: [1, 1, 1]
    Multiplier: 0.514999986
Entities:
  - Entity: 9802306572546035724
    TagComponent:
      Tag: Directional Light
    TransformComponent:
      Position: [0, 0, 0]
      Rotation: [0.763129473, 0.64034152, 0.0667651668, -0.0560226217]
      Scale: [0.99999994, 0.99999994, 1]
    DirectionalLightComponent:
      Radiance: [1, 1, 1]
      CastShadows: true
      SoftShadows: true
      LightSize: 0.5
  - Entity: 1142314663862234558
    TagComponent:
      Tag: Sky Light
    TransformComponent:
      Position: [0, 0, 0]
      Rotation: [1, 0, 0, 0]
      Scale: [1, 1, 1]
    SkyLightComponent:
      EnvironmentAssetPath: D:\Downloads\Compressed\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\Jasmine3D-968aa6fbc18d7a53125667e4602de5401e34c885\JasEditor\assets\env\pink_sunrise_4k.hdr
      Intensity: 1
      Angle: 0
  - Entity: 3948844418381294888
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [-1.48028564, 49.5945244, -2.38418579e-07]
      Rotation: [0.977883637, 0, 0, -0.209149718]
      Scale: [1.99999964, 1.99999964, 2]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [1, 1]
      Density: 1
      Friction: 1
  - Entity: 5178862374589434728
    TagComponent:
      Tag: Camera
    TransformComponent:
      Position: [0, 25, 79.75]
      Rotation: [0.995602965, -0.0936739072, 0, 0]
      Scale: [1, 0.999999821, 0.999999821]
    ScriptComponent:
      ModuleName: Example.BasicController
      StoredFields:
        - Name: Speed
          Type: 1
          Data: 12
    CameraComponent:
      Camera: some camera data...
      Primary: true
  - Entity: 1289165777996378215
    TagComponent:
      Tag: Cube
    TransformComponent:
      Position: [0, 0, 0]
      Rotation: [1, 0, 0, 0]
      Scale: [50, 1, 50]
    ScriptComponent:
      ModuleName: Example.Sink
      StoredFields:
        - Name: SinkSpeed
          Type: 1
          Data: 0
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 0
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [25, 0.5]
      Density: 1
      Friction: 1
  - Entity: 14057422478420564497
    TagComponent:
      Tag: Player
    TransformComponent:
      Position: [0, 22.774044, 0]
      Rotation: [0.942591429, 0, 0, -0.333948225]
      Scale: [6.00000048, 6.00000048, 4.48000002]
    ScriptComponent:
      ModuleName: Example.PlayerCube
      StoredFields:
        - Name: HorizontalForce
          Type: 1
          Data: 10
        - Name: MaxSpeed
          Type: 5
          Data: [0, 0]
        - Name: JumpForce
          Type: 1
          Data: 0
        - Name: VerticalForce
          Type: 1
          Data: 10
    MeshComponent:
      AssetPath: assets\meshes\Sphere1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    CircleCollider2DComponent:
      Offset: [0, 0]
      Radius: 3
      Density: 1
      Friction: 1
  - Entity: 935615878363259513
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [6.88031197, 31.942337, 0]
      Rotation: [0.986578286, 0, 0, 0.163288936]
      Scale: [4.47999954, 4.47999954, 4.48000002]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [2.24000001, 2.24000001]
      Density: 1
      Friction: 1
  - Entity: 1352995477042327524
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [-8.32969856, 30.4078159, 0]
      Rotation: [0.781595349, 0, 0, 0.623785794]
      Scale: [14.000001, 4.47999334, 4.48000002]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [7, 2.24000001]
      Density: 1
      Friction: 1
  - Entity: 8080964283681139153
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [-0.739211679, 37.7653275, 0]
      Rotation: [0.956475914, 0, 0, -0.291811317]
      Scale: [5, 2, 2]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [2.5, 1]
      Density: 1
      Friction: 1
  - Entity: 2157107598622182863
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [-7.60411549, 44.1442184, 0]
      Rotation: [0.989285827, 0, 0, 0.145991713]
      Scale: [4.47999287, 4.47999287, 4.48000002]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [2.24000001, 2.24000001]
      Density: 1
      Friction: 1
  - Entity: 15223077898852293773
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [5.37119865, 43.8762894, 0]
      Rotation: [0.977883637, 0, 0, -0.209149703]
      Scale: [4.47999668, 4.47999668, 4.48000002]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [2.24000001, 2.24000001]
      Density: 1
      Friction: 1
  - Entity: 15861629587505754
    TagComponent:
      Tag: Box
    TransformComponent:
      Position: [-18.2095661, 39.2518234, 0]
      Rotation: [0.967056513, 0, 0, -0.254561812]
      Scale: [4.47999525, 4.47999525, 4.48000002]
    MeshComponent:
      AssetPath: assets\meshes\Cube1m.fbx
    RigidBody2DComponent:
      BodyType: 1
      FixedRotation: false
    BoxCollider2DComponent:
      Offset: [0, 0]
      Size: [2.24000001, 2.24000001]
      Density: 1
      Friction: 1