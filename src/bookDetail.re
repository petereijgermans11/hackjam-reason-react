/*
  TODO: define all possible actions on this component,
   as you would do in Redux.
   Just define the type of the actions, and optional arguments they could have.
   To see the actions that this component uses, look at the `reducer` function
*/
type action;

type state = {
  book: option Database.book
};


let getBook bookId books => {
  switch bookId {
    | None => None
    | Some bookId => {
      try(Some (List.find (fun (book: Database.book) => (string_of_int book.id) == bookId) books)) {
        | Not_found => None
      };
    }
   };
};

let component = ReasonReact.reducerComponent "BookDetail";

let make ::books ::bookId=? ::save _children => {
  ...component,
  initialState: fun _ => {
    let book = getBook bookId books;
     { book: book };
  },
  reducer: fun action state => {
    switch action {
      | TitleChange title => {
        switch state.book {
          | None => ReasonReact.NoUpdate
          | Some book => ReasonReact.Update {...state, book: Some {...book, title}}
        }
      }
      | DescriptionChange description => {
        switch state.book {
          | None => ReasonReact.NoUpdate
          | Some book => ReasonReact.Update {...state, book: Some {...book, description}}
        }
      }
      | ChangeBook book => ReasonReact.Update {...state, book}
    }
  },
  render: fun {state:{book: optionalBook}, reduce} => {
    let bookDetail (book:Database.book) =>
    <div className="card">
      <header className="card-header">
        <p className="card-header-title">
          (Utils.ste ("#" ^ (string_of_int book.id) ^ " - " ^ book.title ^ " details!"))
        </p>
        <a className="card-header-icon">
          <span className="icon">
            <i className="fa fa-angle-down"/>
          </span>
        </a>
      </header>
      <div className="card-content">
        <div className="content">
          <label>(Utils.ste "Title")</label>
          <input
            className="input"
            value=book.title
            onChange=(reduce (fun evt => TitleChange (Utils.valueFromEvent evt)))
            placeholder="title"
          />
        </div>
        <div className="content">
          <label>(Utils.ste "Description")</label>
          <input
            className="input"
            value=book.description
            onChange=(reduce (fun evt => DescriptionChange (Utils.valueFromEvent evt)))
            placeholder="Description"
          />
        </div>
      </div>
      <footer className="card-footer">
        <a className="card-footer-item" href="#/">(Utils.ste "Back")</a>
        <a className="card-footer-item" onClick=(fun evt => save book)>(Utils.ste "Save")</a>
      </footer>
    </div>;

    switch optionalBook {
      | None => <div>(Utils.ste "Unkown book")</div>
      | Some book => bookDetail book
    };
  }
};
