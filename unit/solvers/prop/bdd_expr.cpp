/*******************************************************************\

Module: Unit tests for bdd_expr

Author: Diffblue Ltd.

\*******************************************************************/

/// \file
/// Unit tests for bdd_expr

#include <testing-utils/use_catch.h>

#include <solvers/prop/bdd_expr.h>
#include <util/namespace.h>
#include <util/std_expr.h>
#include <util/symbol_table.h>

SCENARIO("bdd_expr", "[core][solver][prop][bdd_expr]")
{
  symbol_tablet symbol_table;
  namespacet ns{symbol_table};
  bdd_exprt bdd_expr_converter;

  GIVEN("A bdd for x&!x")
  {
    const symbol_exprt var("x", bool_typet());
    const bddt bdd =
      bdd_expr_converter.from_expr(and_exprt(var, not_exprt(var)));
    REQUIRE(bdd_expr_converter.as_expr(bdd) == false_exprt());
  }

  GIVEN("A bdd for (a&b)|!a")
  {
    const symbol_exprt a("a", bool_typet());
    const symbol_exprt b("b", bool_typet());

    const bddt bdd =
      bdd_expr_converter.from_expr(or_exprt(and_exprt(a, b), not_exprt(a)));

    THEN("It is equal to the BDD for (!a|b)")
    {
      const bddt bdd2 = bdd_expr_converter.from_expr(or_exprt(not_exprt(a), b));
      REQUIRE(
        bdd_expr_converter.as_expr(bdd) == bdd_expr_converter.as_expr(bdd2));
    }
  }

  GIVEN("A bdd for (a&!b)")
  {
    const symbol_exprt a("a", bool_typet());
    const symbol_exprt b("b", bool_typet());

    const bddt bdd = bdd_expr_converter.from_expr(and_exprt(a, not_exprt(b)));

    WHEN("It is converted to an exprt")
    {
      const exprt result = bdd_expr_converter.as_expr(bdd);
      THEN("It is equal to the expression (a & !b) or (!b & a)")
      {
        REQUIRE(result.id() == ID_and);
        REQUIRE(result.operands().size() == 2);
        REQUIRE((result.op0() == a || result.op1() == a));
        REQUIRE((result.op0() == not_exprt(b) || result.op1() == not_exprt(b)));
      }
    }
  }
}
