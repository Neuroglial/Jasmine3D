﻿using System.Runtime.CompilerServices;

namespace Jasmine
{
    public class Input
    {

        public static bool IsKeyPressed(KeyCode keycode)
        {
            return IsKeyPressed_Native(keycode);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern bool IsKeyPressed_Native(KeyCode keycode);

    }
}
