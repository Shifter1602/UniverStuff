using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace test
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            using (Form1 frm = new Form1())
            {
                // Show our form and initialize our graphics engine
                frm.Show();
                frm.InitDevices();
                Application.Run(frm);
            }
        }
    }
}
