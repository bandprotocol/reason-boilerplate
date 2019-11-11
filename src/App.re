module Styles = {
  open Css;

  let container =
    style([
      width(`percent(100.)),
      height(`percent(100.)),
      position(`relative),
    ]);
};

[@react.component]
let make = () => {
  <div className=Styles.container> {"Hello, World" |> React.string} </div>;
};
