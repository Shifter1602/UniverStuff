using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.DirectX.DirectInput;


namespace DirectInput
{
    public class Class1
    {
        private Microsoft.DirectX.DirectInput.Device mouse;
        string info;

        public void InitDevices()
        {
            mouse = new Microsoft.DirectX.DirectInput.Device(SystemGuid.Mouse);
            
            mouse.Properties.AxisModeAbsolute = true;
            mouse.SetCooperativeLevel(this,CooperativeLevelFlags.NonExclusive |CooperativeLevelFlags.Background);
            mouse.Acquire();
            if (mouse == null)
            {
                throw new Exception("No mouse found.");
            }
        }

        public void UpdateMouse()
        {
            string info = "Mouse: ";

            //Get Mouse State.
            MouseState state = mouse.CurrentMouseState;

            //Capture Position.
            info += "X:" + state.X + " ";
            info += "Y:" + state.Y + " ";
            info += "Z:" + state.Z + " ";

            //Capture Buttons.
            byte[] buttons = state.GetMouseButtons();
            for (int i = 0; i < buttons.Length; i++)
            {
                if (buttons[i] != 0)
                {
                    info += "Button:" + i + " ";
                }
            }

            //label1.Text = info;
        }



    }
}
