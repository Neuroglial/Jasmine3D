﻿using System;
using System.Runtime.CompilerServices;

namespace Jasmine
{
    public static class MeshFactory
    {

        public static Mesh CreatePlane(float width, float height)
        {
            return new Mesh(CreatePlane_Native(width, height));
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr CreatePlane_Native(float width, float height);

    }
}
