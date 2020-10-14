module type Money = {
  type t;

  let make: int => t;
  let get: t => int;
  let (+): (t, t) => t;
};

module type MoneyConfig = {
  let prefix: string;
};

module Money: (MoneyConfig) => Money = (MoneyConfig) => {
  type t = int;

  let make = a => a;
  let get = a => a;
  let (+) = (a, b) => a + b;
};

module BRLConfig = {
  let prefix = "BRL";
}

module USDConfig = {
  let prefix = "USD";
}

module type Encrypt = {
  type t;
  let make: string => t;
}

module Encrypt: Encrypt = {
  type t = string;
  let make = (a) => a ++ "shauhsas";
};

let password = Encrypt.make("password");

module BRL = Money(BRLConfig);
module USD = Money(USDConfig);

let balanceBRL = BRL.make(12);
let balanceUSD = USD.make(10);

let finalBRL = {
  open! BRL;
  (balanceBRL + BRL.make(10))
};

let backToInt = BRL.get(finalBRL);

type adt = |Loading | Data;

let getHome = () => `home(<p>"Hellooo"->React.string</p>);
let getAbout = () => `home(<p>"About"->React.string</p>);

let render = (state) => {
  switch(state) {
  | `home(el) => el;
  | `about(el) => el;
  };
};

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => getHome());

  <div>
    <button onClick={_ => setState(_ => getHome())}>"Home"->React.string</button>
    <button onClick={_ => setState(_ => getAbout())}>"Abbout"->React.string</button>
    {render(state)}
  </div>
};
