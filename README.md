# 12 coins

The 12 coins problem can be stated as follows: You have 12 similar
looking coins, 11 of which have exactly the same weight. The 12th coin
is a counterfeit and has a different weight, but you don't know if
it's lighter or heavier than the others. You have a scales and are
allowed 3 weighings to determine the counterfeit coin.

This is a description of my solution. It turns out that there are
analytical solutions which don't require the help of a computer and
which extend to larger numbers of coins, but those are not the
solution I found.

I figured out (or, rather, I hoped) that it might be possible to set
up three weighings in advance and from the results determine the
counterfeit coin. By "in advance" I mean that the configuration of the
second weighing doesn't depend on the result of the first, etc. My
instincts told me that in each of the weighings I should weight 4
coins against 4 others and leave the remaining 4 coins alone. Let's
name the 12 coins "A" to "L" and set up the weighings like this:

	  ABCDEFGHIJKL
	1 000011112222
	2 011100021222
	3 101201202012

Line 1 is the configuration for the first weighing, line 2 for the
second and 3 for the third. A "0" in a coin's column means that it
isn't weighed in that round. A "1" means it's on the left scale and a
"2" says it's on the right scale. Hence, according to this table, we
first weigh EFGH against IJKL, then BCDI against HJKL, and finally
ACFK against DGIL.

Now, let's say in our first weighing the left scale is heavier (we
denote that as "1"), in the second one the right scale is heavier
(denoted as "2") and in the third weighing they were level
("0"). Let's assume that the counterfeit is lighter than the other
coins. That means it must have been on the right scale in the first
weighing, on the left in the second and on the bench in the third,
i.e., it should have the numbers "210" in its column. Referring to the
table we note that there is no such coin. Let's assume that it was
heavier, then. In this case it should have "120" in its columns, and
indeed, coin H (and only coin H) fits our criteria.

The question is now, would we always be so lucky to find one, and only
one, matching coin if we weighed according to this table? It turns out
that there are three (very obvious) criteria that our table must fit
for that to be the case:

* In each weighing, there must be the same number of coins in each
  scale (in our case, that number is always 4).

* There must be no two (different) coins which are in the same scale
  in each weighing, because we couldn't differentiate between them.

* There must be no two (different) coins which are in opposite scales
  (or both on the bench) in each weighing, because we couldn't tell if
  one of them is a lighter or the other one is a heavier counterfeit.

As if by magic, the table above fits these criteria, as well as a fourth one:

* Each coin is weighed at least once.

This fourth criterion ensures the we can even tell whether the
counterfeit is lighter or heaver (if one coin is never weighed, we
might be able to tell it's counterfeit because all the others have the
same weight, but we couldn't tell whether it's lighter or heavier).

The above table was calculated with my little program, which you can
download below. It uses a simple brute-force approach, eventually
trying out all possibilities. For only 12 coins this works very well
and gives solutions instantly, but of course it doesn't scale.

Note that if you discard the fourth criterion you can extend the table
with a coin which isn't weighed at all and you'd have a solution to
the same problem with 13 coins.

## Compiling

Simply type

    make

## Usage

Just start the program "coins" and it'll give output lines like this:

    (4276) 100 010 110 210 001 101 022 122 222 012 221 201

Each triple is one column in the weighing table.

## License

This program is licenced under the GNU General Public License.  See
the file `COPYING` for details.

---
Mark Probst <mark.probst@gmail.com>
