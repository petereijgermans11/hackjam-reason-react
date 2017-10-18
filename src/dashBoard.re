let component = ReasonReact.statelessComponent "App";

let book (book:Database.book) => {
  let href = "#/detail/"; /* TODO: should point to correct url with book id */
  <div
    className="column is-one-quarter"
    key=(string_of_int book.id)
  >
    <div className="card">
      <a>
        <div className="card-header">
          <p className="card-header-title has-text-centered">/* Book title */</p>
        </div>
        <div className="card-content">
          <div className="content">
            /* Book description */
            <br />
          </div>
        </div>
        <div className="card-footer">
          <p className="card-footer-item">/* Book category*/</p>
        </div>
      </a>
    </div>
  </div>
};

let make ::books _children => {
  ...component,
  render: fun _ => {
    <section className="section">
      <div className="container">
        <div className="columns is-multiline">
         (Utils.ste "Well done, you rendered the Dashboard. You should now display all books")
        /* TODO display all books */
        </div>
      </div>
    </section>
  }
};
