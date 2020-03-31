// This is a comment in Reason
let rec factorial = n => n <= 0 ? 1 : n * factorial(n - 1);

Js.log(factorial(10));

/**
 * This is a block-comment.
 * Below is the fizzbuzz function
 */
let fizzbuzz = i =>
  switch (i mod 3, i mod 5) {
  | (0, 0) => "FizzBuzz"
  | (0, _) => "Fizz"
  | (_, 0) => "Buzz"
  | _ => Js.Int.toString(i)
  };

for (i in 1 to 100) {
  Js.log(fizzbuzz(i));
};

type person = {
  name: string,
  age: int,
};

let hasan = {name: "Hasan", age: 24};

let display = ({name, age}) => Js.log({j| $name is $age years old.|j});

type my_int =
  | One
  | NegOne
  | Neg
  | Pos;

let getIntType = num =>
  num >= 0 ? num == 1 ? One : Pos : num == (-1) ? NegOne : Neg;

let display_another = ({name, age}) =>
  switch (getIntType(age)) {
  | NegOne => Js.log({j| $name will be born in a year.|j})
  | Neg =>
    Js.log(
      name ++ " will be born in " ++ Js.Int.toString(age * (-1)) ++ " years.",
    )
  | One => Js.log({j| $name is a year old.|j})
  | Pos => Js.log({j| $name is $age years old.|j})
  };

//display(hasan);
//display_another(hasan);

/**
 * refmt reformatted my nested switch statements to using ternary operators
 */
let display_clean = ({name, age}) =>
  age >= 0
    ? age == 1
        ? Js.log({j| $name is a year old.|j})
        : Js.log({j| $name is $age years old.|j})
    : age == (-1)
        ? Js.log({j| $name will be born in a year.|j})
        : Js.log(
            name
            ++ " will be born in "
            ++ Js.Int.toString(age * (-1))
            ++ " years.",
          );

display_clean(hasan);

Js.log("");

Js.log("Display 1:");
for (i in (-10) to 10) {
  let hasan = {name: "Hasan", age: i};
  display(hasan);
};

Js.log("Display 2:");
for (i in (-10) to 10) {
  let hasan = {name: "Hasan", age: i};
  display_another(hasan);
};

Js.log("Display 3:");
for (i in (-10) to 10) {
  let hasan = {name: "Hasan", age: i};
  display_clean(hasan);
};