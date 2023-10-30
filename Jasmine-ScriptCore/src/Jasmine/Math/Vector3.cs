using System.Runtime.InteropServices;

namespace Jasmine
{
    [StructLayout(LayoutKind.Explicit)]
    public struct Vector3
    {
        [FieldOffset(0)] public float X;
        [FieldOffset(4)] public float Y;
        [FieldOffset(8)] public float Z;

        public Vector3(float scalar)
        {
            X = Y = Z = scalar;
        }

        public Vector3(float x, float y, float z)
        {
            X = x;
            Y = y;
            Z = z;
        }


    }
}
