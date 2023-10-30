using System.Runtime.InteropServices;

namespace Jasmine
{
    [StructLayout(LayoutKind.Explicit)]
    public struct Vector2
    {
        [FieldOffset(0)] public float X;
        [FieldOffset(4)] public float Y;

        public Vector2(float scalar)
        {
            X = Y = scalar;
        }

        public Vector2(float x, float y)
        {
            X = x;
            Y = y;
        }
    }
}
