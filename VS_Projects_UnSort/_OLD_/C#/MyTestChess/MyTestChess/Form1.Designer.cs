namespace MyTestChess
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.BP1 = new System.Windows.Forms.Label();
            this.BP2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BP1
            // 
            this.BP1.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.BP1.Image = ((System.Drawing.Image)(resources.GetObject("BP1.Image")));
            this.BP1.Location = new System.Drawing.Point(343, 109);
            this.BP1.Name = "BP1";
            this.BP1.Size = new System.Drawing.Size(74, 74);
            this.BP1.TabIndex = 8;
            this.BP1.Text = "label1";
            this.BP1.Click += new System.EventHandler(this.BP1_Click);
            // 
            // BP2
            // 
            this.BP2.BackColor = System.Drawing.Color.Transparent;
            this.BP2.ForeColor = System.Drawing.Color.Transparent;
            this.BP2.Image = global::MyTestChess.Properties.Resources.Белая_пешка_тест;
            this.BP2.Location = new System.Drawing.Point(120, 109);
            this.BP2.Name = "BP2";
            this.BP2.Size = new System.Drawing.Size(74, 74);
            this.BP2.TabIndex = 9;
            this.BP2.Text = "label1";
            this.BP2.Click += new System.EventHandler(this.BP2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.ClientSize = new System.Drawing.Size(684, 662);
            this.Controls.Add(this.BP2);
            this.Controls.Add(this.BP1);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Click += new System.EventHandler(this.Form1_MClick);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label BP1;
        private System.Windows.Forms.Label BP2;




    }
}

