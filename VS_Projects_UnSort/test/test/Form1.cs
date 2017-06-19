using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX.DirectInput;

namespace test
{
    public partial class Form1 : Form
    {
        private Microsoft.DirectX.DirectInput.Device mouse;
        public Form1()
        {
            InitializeComponent();
            timer1.Enabled = true;
        }

        public void InitDevices()
        {
            mouse = new Microsoft.DirectX.DirectInput.Device(SystemGuid.Mouse);
            mouse.Properties.AxisModeAbsolute = true;
            //mouse.Properties.
            //mouse.SetCooperativeLevel(this, CooperativeLevelFlags.Exclusive);
            mouse.SetCooperativeLevel(this,CooperativeLevelFlags.NonExclusive |CooperativeLevelFlags.Background);
            mouse.Acquire();
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

            label1.Text = info;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            UpdateMouse();
        }



    }
}
