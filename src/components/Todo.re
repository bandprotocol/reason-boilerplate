type todo = {
  id: int,
  name: string,
	completed: bool
};

module Styles = {
  open Css;

  let todo =
    style([
      
    ]);
};

[@react.component]
let make = (~todo,~onToggle) => {
  <div onClick=((_) => onToggle())>
  <input type_="checkbox" checked=(todo.completed) ></input> {React.string(todo.name)}
  </div>
};
