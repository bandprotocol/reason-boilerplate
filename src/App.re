module Styles = {
  open Css;

  let container =
    style([
      width(`percent(100.)),
      height(`percent(100.)),
      position(`relative),
    ]);
};

type state = {
  todos: list(Todo.todo)
};

type action = |AddTodo(Todo.todo) | ToggleTodo(int);

[@react.component]
let make = () => {
  let (text, setText) = React.useState(() => "")
  let ({todos}, dispatch) = React.useReducer((state,action) => {
    switch action {
      | AddTodo(todo) => { todos: [todo, ...state.todos]}
      | ToggleTodo(id) =>  
        let todos = List.map((todo:Todo.todo) => 
          todo.id === id ? 
          {...todo, completed:!todo.completed}:
           todo,
           state.todos);
        {todos: todos}
    }
  }, {
    todos: [
      {id: 0, name: "Todo1", completed: false}
    ]
  });
  let numTodos = List.length(todos);
  let handleInputText = () => {
    dispatch(AddTodo({id: numTodos, name: text, completed: false}))
    setText(_ => "")
  };
  <div className=Styles.container>
    <h1>{React.string("Todos")}</h1>
    
    <div>
     {
       React.array(Array.of_list(
            List.map((todo:Todo.todo) => <Todo key={string_of_int(todo.id)} todo onToggle=(() => dispatch(ToggleTodo(todo.id))) />, todos)
        ))
      }
     </div>
     <input value=text type_="text" placeholder="Write todo" 
      onKeyDown=((evt) => 
        if(ReactEvent.Keyboard.key(evt) == "Enter"){
         handleInputText()
        }
      )
     onChange=((evt) => setText((evt -> ReactEvent.Form.target##value)))/>
    <button onClick=((_) => handleInputText())>(React.string("Add Todo"))</button>
    <div>{React.string(string_of_int(numTodos) ++ "todo")}</div>
  </div>
};
