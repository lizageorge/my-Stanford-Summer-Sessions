# Proofwriting Checklist
### Adapted from the "proofwriting checklist" handout and lecture notes

## Main Checklist;
- [ ] Clearly articulate your start and end points
	- begin your proof with "*Theorem:...*", and use "*Proof..."* to denote the start of the actual proof
	- for every substep and leap in logic you make, clearly state what it is and why it's neeeded ([] "we need to prove y for x...(prove y...)...y is true, which is what we needed to show")
	- this also helps you double check that you're breaking down the logic in your head into small-enough, thoroughly-proven portions
	`Proof: Consider an arbitrary x ∈ A. Since x ∈ A and A ⊆ B, we see that x ∈ B.
	And, since x ∈ B and B ⊆ C, we see that x ∈ C, as required. ■ `
	vs.
	`Proof: Let A, B, and C be arbitrary sets where A ⊆ B and B ⊆ C. We will prove that A ⊆ C. To do so, choose an arbitrary x ∈ A. We will prove that x ∈ C. Since x ∈ A and A ⊆ B, we see that x ∈ B. And, since x ∈ B and B ⊆ C, we see that x ∈ C, which is what we needed to show. ■`
- [ ] Make each sentence “load-bearing.”
	- every sentence in the proof should do one of these things:
		- *Set up a goal*:  proofs should start off with an introduction that clearly articulates a start and end point, and also set up what it is you're trying to prove for auxillary steps
		- *Introduce a new variable*: 
			- If you’re proving something universally-quantified, you might want to say something like “let x be an arbitrary bananafish,” 
			- If you’re proving something existentially-quantified you might want to say something like “since n is even, we know there is an integer k such that n = 2k.”
		- *Combine preceding results into something new*: make progress toward the result by taking some number of preceding statements and deriving some new, mathematically rigorous result from those preceding statements. For example, you might say something like “since n = 2k, we see that n2 = 2(2k)^2” or “since A ⊆ B and x ∈ A, we learn that x ∈ B"
	- this rule is important bc it forces you to read over first drafts to eliminate anything that's unecessary or too high-level/non-rigourous, to make everything precise (you'll have to use mathematical definitions instead of going by assumptions or tendencies), and it's the standard for mathematical proofs to be minimalistic and consise (as opposed to mathematical expositions)
- [ ] Scope and properly introduce variables.
	- Variables in mathematical proofs obey a similar sort of to vars in programming languages like C++/Java. 
	- For every variable in a proof, you should explicitly articulate (1) the name of the variable, (2) what value it represents, and (3) where it comes from.
	- Every variable should be one of the following three types
		- *An arbitrarily-chosen value*: doesn’t represent some specific number, set, or quantity, but rather an arbitrarily-chosen value. Often used in proving universally-quantified statements. 
			- [] if you want to prove the claim “for any natural number n, if n is even, then n2 is even,” you might introduce a variable n like: "Let n be an arbitrary even natural number." or "Consider an even natural number n." Here, we’re indicating that the variable is named n, its value is some even natural number, and that it’s chosen arbitrarily.
		- *An existentially instantiated value*: for when you know that some quantity with some property must exist, but you don’t know what it is. 
			- [] if you know that n is an even natural number, you know that n must be twice some other natural number, and so you might give that natural number a name, like "Since n is even, there is some integer k such that n = 2k."
			- [] if you know that "x is congruent to y modulo b" and x and k have already been chosen arbitrarily for a univerversal statement, you should declare y as the integer that would follow that formula.
			- It’s important to note that this number is not chosen arbitrarily. That would imply that any choice of k would work here, but that’s not true: there’s only one choice of k you can pick where n = 2k/where x is congruent to y to mudulo b. Rather, k is called an existentially instantiated variable, because we know that
		- *An explicitly chosen value:* just a variable holding a larger expression for the sake of convenience and readability. For example, you might say "let the set D = { x ∈ S | x ∉ f(x) }" instead of having to repeat  "{ x ∈ S | x ∉ f(x) }" over and over again. Like a const in programming languages
		- *A true placeholder*: in some very rare occassions, variables are truly just placeholders that don't hold any real value.
			- [] g. For example, in set-builder notation, we use placeholder variables to denote the name of some unknown quantity ([] { n ∈ ℕ | n is even and n2 > 48 } ). In this context, n does not represent a value, it just lets us write the expression “n is even and n2 > 48” in a way that’s clear and easy to follow. It’s an error to try to reference the number n out of this context.
	- common errors;
		- accidentally re-defining variables: 
			- [] here, saying "any x /in A" is like re-defining a var in code. there's possibly two different 'x' vars going on is, and isn't unambigous.
				- `To show this, consider any x ∈ A. Since x ∈ A and we know that any x ∈ A must also be an element of B, we see that x ∈ B.`
				- vs
				- `To show this, consider any x ∈ A. Since x ∈ A and A ⊆ B, we see that x ∈ B.`
		- not defining a variable properly when you switch between  telling the reader *what you’re going to prove* and then *actually going and proving it*
			- `Proof: Let A and B be arbitrary sets. We will prove that A ∩ B ⊆ A by showing that every x ∈ A ∩ B satisfies x ∈ A. To see this, notice that since x ∈ A ∩ B, we know that x ∈ A and x ∈ B. In particular, this means that x ∈ A, as required. ■`
			- vs.
			- `Proof: Let A and B be arbitrary sets. We will prove that A ∩ B ⊆ A by showing that every x ∈ A ∩ B satisfies x ∈ A. To see this, consider any x ∈ A ∩ B. Notice that since x ∈ A ∩ B, we know that x ∈ A and x ∈ B. In particular, this means that x ∈ A, as required. ■`
		- this rule is important bc it forces you to be very, very precis ein what you're talking about. You can't make any broad statements, you're always refering to a very specifically defined object. "From experience, proofs that do not pin things down at this level of detail tend to have more errors and to miss important but subtle details.". It also makes it earier to you the writer to understand what you're saying, and spot any confusions you might have made.
- [ ] Make specific claims about specific variables.
	- you should always make *specific, precise claims about named variables* instead of *broad, general claims about all objects of a certain type*. Even if your underlying logic is correct as you refer to specific mathematical definitions, you should use the same syntax that definition/idea does!
	- [] `Since A ⊆ B, every element of A is an element of B` vs `Consider any element x ∈ A. Since A ⊆ B and x ∈ A, we see that x ∈ B`
	- [] `The function f maps different inputs to different outputs` vs `Consider any arbitrary x and y where x ≠ y. Then we know that f(x) ≠ f(y).` 
	- this rule is important bc it allows you to realize, if you can't pin down a precise and specific definition/statement, your logic might be flawed. It's easy to rely on intuitions, but sometimes your intuitions contradict specific mathematical logic. If you can formalize your intuitions with mathematical precision, you're probably on the right track. 
☐ Don’t repeat definitions; use them instead.
☐ Write in complete sentences and complete paragraphs.
☐ Distinguish between proofs and disproofs.

11 / 21
The only way to know which of your intuitions are good and which need tuning is to explicitly
validate those intuitions by attempting to formalize them mathematically. To do so, we ask
that you speak with mathematical precision and to show how specific applications of definitions give you your result. If you’re able to do this, great! It likely means your intuition is pointing you the right way. If not, that might indicate that your intuition might be suggesting something that the math says isn’t true, in which case it’s a good thing that you tried formalizing
things! At that point, you should back up, pause, and see whether the result is still true for
some other reason or whether you need to reshape your intuition for the future.
12 / 21
Don’t Repeat Definitions; Use Them Instead
Mathematical definitions are wonderfully useful. They give us a way to take an intuitive idea
like “even numbers” and to formalize them in a way that lets us manipulate them in proofs.
Most mathematical proofs will in some way, shape, or form touch on formal definitions. However, you should avoid restating definitions purely in the abstract and instead focus on how
those definitions are specifically useful or relevant for what you’re trying to do. For example,
we recommended replacing statements like the ones on the left with one like what’s on the
right:
We know that x ∈ A. Since A ⊆ B, we know
that every element of A is an element of B.
Thus we see that x ∈ B.
We know that x ∈ A. Since A ⊆ B, we know
that every x ∈ A satisfies x ∈ B. Therefore,
we see that x ∈ B.
→ Since x ∈ A and A ⊆ B, we see that x ∈ B.
We know that x ∈ A. Since A ⊆ B, we know
that every z ∈ A satisfies z ∈ B. Therefore,
we see that x ∈ B.
There are a few reasons why it’s wise to avoid repeating definitions in the abstract. First, you
can assume that the reader knows all of the relevant terms and definitions that are needed in
your proofs. Your job as a proofwriter is not to convince the reader of what the definitions are,
but to show how those definitions interact with one another to build into some result. In that
sense, repeating a definition in the abstract, like what’s done above and to the left, doesn’t
actually contribute anything to the argument you’re laying out. The reader already knows the
definition, so that sentence is fully redundant.
Second, restating definitions in the abstract risks violating other checklist items. Let’s go one
at a time through the three options on the left that we advise against. The first one is far too
general (“every element of A is an element of B”) and therefore breaks our advice of making
specific claims about specific variables. The second one (“every x ∈ A satisfies x ∈ B”) is a variable scoping error – is x the specific value referred to in the first sentence, or is it a placeholder? The third one is making specific claims about the variable z and doesn’t have a scoping
error, but in that case z is purely a placeholder – it doesn’t refer to any value. In each of those
cases, you can safely delete things.
And finally, restating definitions in the abstract just makes things longer. Compare the three
options to the left to the one on the right. All three of those proof fragments are significantly
longer than the more concise and direct version shown to the right.
Why we enforce this rule: Brevity. Simply put, this rule is a great way to reduce the amount
of writing you do and to keep your proofs short. 
13 / 21
The other reason we enforce this rule is that it reduces the space of possible errors you can
make. As we’ve mentioned earlier, using placeholder variables is an easy way to run into trouble, either by confusing one variable for another or by thinking you’ve proved something that
you actually haven’t. Asking that you apply definitions rather than repeat them reduces the
number of placeholder variables you have to work with in your proof, eliminating many potential opportunities for error.
14 / 21
Write In Complete Sentences and Complete Paragraphs
Although proofs exist to convey mathematical arguments, the expectation is that they should
be written in grammatically-correct English sentences and in paragraph form.
A good test we recommend applying to your proofs is what we call the mugga mugga test.
Take your proof and try reading it out loud, replacing all the mathematical content with the
phrase “mugga mugga.” If what comes back is grammatically correct, then you’re on the right
track! On the other hand, if what you write is hard to read aloud, or just plain doesn’t sound
right, it means that you might need to go back and correct things. As an example, here’s a notso-great proof that if n is even, then n2 is even:
 Incorrect! Proof: If n is even, n = 2k. n2 = 4k
2, which is 2(2k
2). 2k
2 ∈ ℤ, so n2 is even. ■
Let’s apply the mugga mugga test to this proof, one sentence at a time. Here’s the first sentence:
Original Mugga Mugga Version
 If n is even, n = 2k. If n is even, mugga mugga.
The mugga-muggaified version of this sentence isn’t grammatically correct – it has no subject
and no verb. The reason for this is that the subject of the original sentence is n and the verb is
“equals,” but since we’ve written out the equality using the equals sign, it got mugga-muggified
in the updated version of the sentence.
More generally:
Tip: Avoid writing sentences where mathematical notation must be treated as a verb.
So what should we do instead? Let’s begin with what you shouldn’t do. Don’t rewrite the sentence like this in order to pass the mugga mugga test:
 If n is even, n equals 2k.
This technically passes the mugga mugga test, but it’s doing so by taking a clear mathematical
statement (n = 2k) and rendering the unambiguous, precise mathematical symbol = in English.
The whole reason for having mathematical symbols in the first place is so that we can be precise with our notation, and this is a step in the wrong direction.
Instead, consider rewriting the sentence in a way that introduces a new subject and a new
verb. There are many ways that we can do this. Here are a few options to choose from:
Original Mugga Mugga Version
If n is even, then we can write n = 2k.
If n is even, then we can write mugga
mugga.
Since n is even, we see that there is some
integer k such that n = 2k.
Since n is even, we see that there is some
integer k such that mugga mugga.
15 / 21
Because n is even, it can be expressed as
n = 2k for some integer k.
Because n is even, it can be expressed as
mugga mugga for some integer k.
Notice how in each sentence we’ve introduced an explicit subject and verb in a way that passes
the mugga mugga test.
16 / 21
Let’s look at this second sentence:
Original Mugga Mugga Version
n2 = 4k
2, which is 2(2k
2). Mugga mugga, which is mugga mugga.
Again, we’re failing the mugga mugga test because the subject and verb of the sentence are
expressed in mathematical notation. We’d be better off rewriting this sentence in one of the
following ways:
Revision Mugga Mugga Version
We can rewrite the expression n2 = 4k
2 as
n2 = 2(2k
2).
We can rewrite the expression mugga
mugga as mugga mugga.
Rewriting 4k
2 as 2(2k
2), we see that
n2 = 2(2k
2).
Rewriting mugga mugga as mugga
mugga, we see that mugga mugga.
A common theme in the mugga mugga test is that you should avoid using math notation as
the verb in a sentence. Similarly, you should avoid using mathematical notation or shorthands
to abbreviate parts of sentences. There are a number of shorthands that have been developed
over the years, primarily for use on blackboards where writing out longhand can take a while.
For example, the word “therefore” is often abbreviated ∴, and the word “because” is often abbreviated ∵. These shorthands are just that – they’re shorthands – and should not be used in
mathematical proofs except if you’re trying to write something up quickly and on a blackboard. For example, please, please, please don’t write the following:
∵ n is even, n = 2k for some integer k, ∴ n2 = 4k
2 = 2(2k
2), ∴ n2 is even ∵ n2 = 2m for m = 2k
2.
This one really, really, really fails the mugga mugga test:
Original Mugga Mugga Version
∵ n is even, n = 2k for some integer k,
∴ n2 = 4k
2 = 2(2k
2), ∴ n2 is even ∵ n2 = 2m
for m = 2k
2.
Mugga mugga n is even, mugga mugga
for some integer k, mugga mugga mugga
mugga, mugga mugga n2 is even mugga
mugga mugga mugga for mugga mugga.
This almost reads like a parody of a terrible math lecture. So please don’t write proofs like
this.
Just as you’re expected to write in complete sentences, you’re expected to write in complete
paragraphs. This means that your proofs should not consist of bulleted or numbered lists of
statements. For example, please don’t write proofs like these:
• Let n be an even integer.
• Since n is even, we can write n = 2k for some integer k.
• Then n2 = 4k
2.
• So n2 = 2(2k
2).
• Let m = 2k
2.
17 / 21
• [etc.]
Although we can see what this proof is saying, this just isn’t the format that’s expected and so
you shouldn’t structure things this way.
Why we enforce this rule: We primarily enforce this rule because this is the standard convention in mathematical writing and we’re hoping to train you to communicate mathematics
effectively. Additionally, this rule makes proofs much easier to read by requiring you, the
writer, to link your ideas together in a way that helps the argument flow.
18 / 21
Distinguish Between Proofs and Disproofs
The short version of this section goes as follows:
• A proof is an argument that explains why some theorem is true.
• A disproof is an argument that explains why some claim is false.
• Don’t write a proof by contradiction when you mean to write a disproof.
Now, the longer version.
If you are writing a proof of a result, that result is called a theorem. The term “theorem” specifically refers to a statement that is true under a specific set of assumptions. The general template for writing a proof looks like this:
Theorem: [ statement that you want to prove is true ]
Proof: [ some argument establishing why that statement is true ]
On the other hand, let’s suppose that you have some statement that is not true, and you want
to show that that statement is indeed false. This is called a disproof. Since you’ll be showing
that a given statement is not true, it is not appropriate to call that statement a “theorem.” Remember – the term “theorem” specifically refers to a statement that’s true! When you’re writing a disproof, you’d typically refer to the statement in question as a claim (something that’s
being proposed, but which isn’t necessarily true) to indicate that the statement should be
treated with some suspicion.
The general template for writing a disproof looks like this:
Claim: [ statement that you want to prove is false ]
Disproof: [ some argument establishing why that statement is false ]
Be very careful not to mix and match the terminology from proofs and disproofs. For example,
suppose you want to disprove the claim that if A and B are sets, then A ∩ B = Ø. (Here, this
statement is false because it’s implicitly a universally-quantified statement, and there indeed
exist pairs of sets with a nonempty intersection). Here’s how you shouldn’t do this:
 Incorrect! Theorem: If A and B are sets, then A ∩ B = Ø.
 Incorrect! Proof: We will show that this statement is not true. Consider the sets A = ℕ
and B = ℕ. Notice that A ∩ B = ℕ ∩ ℕ = ℕ, so A ∩ B ≠ Ø. ■
The problem with the above setup is that, to a quick glance, it seems like you’re doing exactly
the opposite of what you’re actually doing. By labeling the statement as a theorem and the
argument as a proof, you are signaling to your reader that you think that the statement is true
and that you’re going to provide a justification for it. If they then read your proof, they’re going 
19 / 21
to be terribly confused, because you’re starting your proof off by saying that you’re going to
show that your theorem – something that’s supposed to be true – isn’t actually true.
A better way to write this would be to do something like this:
20 / 21
Claim: If A and B are sets, then A ∩ B = Ø.
Disproof: We will show that the negation of this statement is true, namely that there exist sets
A and B where A ∩ B ≠ Ø.
Consider the sets A = ℕ and B = ℕ. Notice that A ∩ B = ℕ ∩ ℕ = ℕ, so A ∩ B ≠ Ø. ■
Take a look at how this argument is laid out. First, the statement in question is marked as a
claim, not a theorem, so someone reading over your work will get cued in that you’re simply
stating something rather than arguing that it’s true. Next, the argument is explicitly labeled as
a disproof, indicating to the reader that they’re about to see why the claim isn’t true. The specifics of that argument then outline a reason why the claim is false – specifically, it says that
the negation of the claim is true, then explains why that’s the case.
Another common error we see people make when writing out disproofs is to mix up two related but different concepts: disproofs (arguments that show why a claim isn’t true) and
proofs by contradiction (arguments that show that a claim is true by assuming for the sake of
argument that it isn’t). Although both a disproof and a proof by contradiction will involve
working with the negation of a statement, they proceed very differently from one another. In
a disproof, you take the negation of the statement in question, then prove that the negation is
true. In a proof by contradiction, you assume that the negation is true, derive a contradiction,
and then claim that, as a result, the statement must have been true all along. In other words,
a disproof explains why something is not true, and a proof by contradiction explains why
something is true. As a result, you have to be careful not to mix these concepts up.
For example, here’s another example of how not to write a disproof:
Claim: If A and B are sets, then A ∩ B = Ø.
 Incorrect! Disproof: Assume for the sake of contradiction that there exist sets A and
B where A ∩ B ≠ Ø.
Consider the sets A = ℕ and B = ℕ. Notice that A ∩ B = ℕ ∩ ℕ = ℕ, so A ∩ B ≠ Ø. ■
This disproof says that we should start by assuming that the negation of the claim in question
here is true. Remember that the whole point of a disproof is to explicitly prove that the negation of the claim is true, so if we start off by assuming the negation of the claim, there’s nothing left to do!
Why we enforce this rule: This rule is designed to minimize confusion on the part of the person reading your proof. If you are writing a disproof of a result and structure it as though
you’re writing a proof of a theorem, the person reading your disproof will go in with completely incorrect expectations about what they’re going to find. In the best case, a reader will
quickly figure this out and begin rereading what you wrote from the top, which isn’t the best
use of their time. In the worst case, the reader will be totally lost and not understand what it
is that you’re trying to do. (There’s an even worse case, and that’s where a TA will look at what 
21 / 21
you wrote, say “well, you got the wrong answer, because you’re trying to prove something
false” and then give you zero points without reading further, but we’ll ignore that for now. )