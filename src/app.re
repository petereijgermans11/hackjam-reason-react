open Routes;

/* State of our component */
type state = {
  books: Database.books
};

/* Actions that can be send to our reducer function */
type action =
  | UpdateBook Database.book
  | DeleteBook int
  | AddBook string;

/* This is the way we declare a component */
let component = ReasonReact.reducerComponent "App";

/*
  'make' is the function a JSX element will call.
  e.g.: this make function will be called with <App/>
*/
let test ::route _children => {
  ...component,
  initialState: fun () => {
    books: Database.books
  },
  /*
    TODO: reducer takes action and state as args
    pattern match on actions and return the new state
  */
  reducer: fun () _ => ReasonReact.NoUpdate,
  render: fun {state: {books}, reduce} => {
  /* TODO: write functions that our components needs (future) */
  let page = switch route {
    | DashBoardRoute => <DashBoard books/>;
    /* TODO: pattern match with all routes the app has  */
  };

  <div>
    /* TODO: display the Navbar component */
    (page)
  </div>
  }
};

