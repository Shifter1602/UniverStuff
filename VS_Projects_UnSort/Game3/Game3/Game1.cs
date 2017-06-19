using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System.Windows;

namespace Game3
{
    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1 : Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        VertexPositionColor[] verts;
        BasicEffect effect;
        VertexBuffer buffer;
        Vector3 position;
        Texture2D image;
        float rotY,angle;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            //GraphicsDevice.RasterizerState = RasterizerState.CullNone;
            verts = new VertexPositionColor[3]
            {
                new VertexPositionColor(new Vector3(0.0f,1.0f,0.0f), Color.Red),
                new VertexPositionColor(new Vector3(-1.0f,-1.0f,0.0f), Color.Blue),
                new VertexPositionColor(new Vector3(1.0f,-1.0f,0.0f), Color.White),
                
            };
            effect = new BasicEffect(GraphicsDevice);
            buffer = new VertexBuffer(GraphicsDevice, VertexPositionColor.VertexDeclaration, 3, BufferUsage.WriteOnly);
            buffer.SetData(verts);
            position = new Vector3(0.0f, 0.0f, 10.0f);


            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            image = Content.Load<Texture2D>("BitmapExport");
            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
            
            
            
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();

            float deltaTime = (float)gameTime.ElapsedGameTime.TotalSeconds;
            rotY += deltaTime;
            angle += 0.01f;

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            
            GraphicsDevice.Clear(Color.CornflowerBlue);
            GraphicsDevice.RasterizerState = RasterizerState.CullNone;
            
            
            spriteBatch.Begin();

            effect.Projection = Matrix.CreatePerspectiveFieldOfView(MathHelper.PiOver4, GraphicsDevice.Viewport.AspectRatio, 0.0001f, 100000.0f);
            effect.View = Matrix.CreateLookAt(new Vector3(0, 0, -5), Vector3.Backward, Vector3.Up);
            effect.World = Matrix.Identity * Matrix.CreateRotationY(rotY) * Matrix.CreateTranslation(position) * Matrix.CreateRotationZ(rotY);
            effect.VertexColorEnabled = true;
            foreach (EffectPass pass in effect.CurrentTechnique.Passes)
            {
                pass.Apply();
                GraphicsDevice.DrawUserPrimitives<VertexPositionColor>(PrimitiveType.TriangleStrip, verts, 0, 1);
            }

            
            //spriteBatch.Draw(image, new Rectangle(0,0,image.Width,image.Height),Color.White);
            spriteBatch.End();
            

            base.Draw(gameTime);
        }
    }
}
