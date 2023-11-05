using System;
using Jasmine;

public class RuntimeMesh : Entity
{

	public Mesh MyMesh;

	void OnCreate()
	{
		GetComponent<MeshComponent>().Mesh = MyMesh;
	}

}
