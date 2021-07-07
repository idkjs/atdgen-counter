/**************************************************************************/
/*                                                                        */
/*                                 OCaml                                  */
/*                                                                        */
/*                         The OCaml programmers                          */
/*                                                                        */
/*   Copyright 2018 Institut National de Recherche en Informatique et     */
/*     en Automatique.                                                    */
/*                                                                        */
/*   All rights reserved.  This file is distributed under the terms of    */
/*   the GNU Lesser General Public License version 2.1, with the          */
/*   special exception on linking described in the file LICENSE.          */
/*                                                                        */
/**************************************************************************/

external id: 'a => 'a = "%identity";
let const = (c, _) => c;
let flip = (f, x, y) => f(y, x);
let negate = (p, v) => !p(v);

// exception Finally_raised(exn);
// let raiseError = msg => Js.Exn.raiseError(msg) |> ignore;

// let raiseErrorAndReturn = msg => Js.Exn.raiseError(msg);

// let throwError: Js.Exn.t => unit = [%raw {|
// function(err){
//   throw err;
// }
// |}];

// let () =
//   PrintExec.register_printer @@
//   (
//     fun
//     | Finally_raised(exn) =>
//       Some("Fun.Finally_raised: " ++ PrintExec.to_string(exn))
//     | _ => None
//   );

// let protect = (~finally: unit => unit, work) => {
//   let finally_no_exn = () =>
//     try(finally()) {
//     | e =>
//       let bt = PrintExec.get_raw_backtrace();
//       PrintExec.raise_with_backtrace(Finally_raised(e), bt);
//     };

//   switch (work()) {
//   | result =>
//     finally_no_exn();
//     result;
//   | exception work_exn =>
//     let work_bt = PrintExec.get_raw_backtrace();
//     finally_no_exn();
//     PrintExec.raise_with_backtrace(work_exn, work_bt);
//   };
// };
