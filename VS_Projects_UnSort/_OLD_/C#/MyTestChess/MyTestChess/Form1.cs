using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


struct kletky
{
    public int locationX;
    public int locationY;
}


namespace MyTestChess
{

    
    public partial class Form1 : Form
    {
        kletky[,] kletki= new kletky [8,8];
        
       
        public Form1()
        {

            for (int i = 0; i < 32; i++)
            {
                activefigure.act[i] = 0;
            }
            kletki[0, 0].locationX = 45;
            kletki[0, 0].locationY = 34;
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    kletki[i, j].locationX = 45+75*i;
                    kletki[i, j].locationY = 34+74*j;
                }


            chess bp1 = new chess();
            chess bp2 = bp1; bp2.id = 2; bp2.name = "BP2"; bp2.posicition = new int[] { 1, 2 };



            

            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BP2.Location = new Point(0,0);
        }




        private void Form1_MClick(object sender, EventArgs e)
        {
           
            if (activefigure.act[2] == 1)
            {
                Point cvo = this.PointToClient(Cursor.Position);
                if (cvo.X >= (BP2.Location.X) && cvo.X < (BP2.Location.X + 74))
                {
                    if (cvo.Y >= (BP2.Location.Y + 74) && cvo.Y < (BP2.Location.Y + 148))
                    {

                        BP2.Location = new Point(BP2.Location.X, BP2.Location.Y + 74);
                    }
                    if (cvo.Y >= (BP2.Location.Y + 148) && cvo.Y < (BP2.Location.Y + 222))
                    {

                        BP2.Location = new Point(BP2.Location.X, BP2.Location.Y + 148);
                    }
                }
                BP2.Image = MyTestChess.Properties.Resources.Белая_пешка_тест;
                activefigure.act[2] = 0;
            }

        }
        private void Form1_MClick()
        {
            int CursorX = Cursor.Position.X;
            int CursorY = Cursor.Position.Y;
            if(CursorX>=kletki[0, 2].locationX && CursorX>=kletki[0, 3].locationX)
                if (CursorY >= kletki[0, 2].locationY && CursorY >= kletki[1, 2].locationY)
                {
                    BP1.Location = new Point(kletki[0, 2].locationX, kletki[0, 2].locationY);
                }
        }
       

        private void BP1_Click(object sender, EventArgs e)
        {
           
            int CursorX = Cursor.Position.X;
            int CursorY = Cursor.Position.Y;
            int peshkax = BP1.Location.X;
            int peshkay = BP1.Location.Y;
            
         

        }

        private void BP2_Click(object sender, EventArgs e)
        {
            if (activefigure.act[2] == 0)
            {
                BP2.Image = MyTestChess.Properties.Resources.Белая_пешка_тест_2;
                activefigure.act[2] = 1;
            }
            else
            {
                BP2.Image = MyTestChess.Properties.Resources.Белая_пешка_тест;
                activefigure.act[2] = 0;
            }
            

        }

       
     

        
    }
    class chess
    {
        public int id; //идентификатор
        public string name; //имя фигуры/пешки
        public string party = "white"; //сторона
        public bool act = false; //Активна ли(если на нее нажал пол-ль и она должна ходить, то true
        public int[] posicition = new int[2]; //позиция на доске

        // Default constructor:
        public chess()
        {
            id = 1; name = "BP1"; posicition = new int[] { 1, 2 };

            //.......

        }
        ~chess() { }
    }
    static class activefigure
    {
        public static int[] act= new int[32];
    }
}
