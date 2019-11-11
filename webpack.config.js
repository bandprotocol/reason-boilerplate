const path = require("path");

module.exports = {
  entry: "./src/Index.bs.js",
  // If you ever want to use webpack during development, change 'production'
  // to 'development' as per webpack documentation. Again, you don't have to
  // use webpack or any other bundler during development! Recheck README if
  // you didn't know this
  mode: "development",
  // mode: "production",
  output: {
    path: path.join(__dirname, "bundleOutput"),
    filename: "index.js"
  },
  module: {
    rules: [
      {
        test: /\.(png|jpg|gif|svg)$/i,
        use: [
          {
            loader: "url-loader",
            options: {
              fallback: require.resolve("responsive-loader")
            }
          }
        ]
      }
    ]
  }
};
