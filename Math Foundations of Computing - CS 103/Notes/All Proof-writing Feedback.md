# All Proof-writing Feedback

## Intuition
- Always work off of concepts that are *already* proven, not your intuition, and not on outside knowledge
	- Pset1 Checkpoint, problem 3; for modular arithmetic proofs we were relying on our prior definitions of what "mod" means, but we don't have any proof yet that remainders have to be unique to pairs of dividends and divisors.
- Be very careful on where you use the word "abitrary"
- when negating implications, be very careful to keep your antecedent untouched! nothing about it should change, you only have to work with the negation of the consequent 
- Don't mix up the defintions for a function to be deterministic and injective
- always try and work you proofs *forward* - for universal statement proofs, instead of arranging/assuming something to fit the antecedent and proving it fits the requirements in the theorem, prove... 

## Execution
- Always scope and introduce all variables (|||)
	- When giving examples, give clear and specific examples
		- when giving examples of sets, give example values to the sets
		- use integers instead of letters for specific examples
	- Instead of just saying "We will prove[theorem]" as your first sentence, include "Let x, y, and z be arbitrary elements/elements such that...We will prove that..."
- You should specify what is is that you are trying to prove and what you are assuming. The first sentence of a proof is ideally something like "We will prove..."
- you should always state exactly what your *assuming* in a proof - usually the antecedent of an implication, etc.
- especially for non-direct proofs, conclude it with an additional statement stating what you have just shown and how that relates to the original theorem.
- don't repeat definitions
- don't include tidbits that you won't use later

## Readability, Style


## Practice Tests
- **Practice Midterm #1** - 27-30/48 ahhhh (this might gain more with partial credit)
	- problem one - 11/12
		- oftentimes very wordy, and you repeat definitions (say "In order to prove this, we need to show that ..." instead of "In other words...")
		- but spot on logic, and good on following the guide's template for equivalence relations
	- problem two -?? maybe 2/12
		- i could not answer this, even in my second shot..
		- good to notice that both directions of the implication have to be proven
		- remember, when proving an implication, you don't have to start at the antecedent and work your way to the consequent. You just have to prove that, if the antecedent is assumed true, the consequent is true. 
	- problem three - 8??/12
		- logic for first half was good, explanation was wonky
		- i had a different logic process for second part...
		- ^ same for third part. idk if it even works
	- problem four - 6/12 
		- careful to fully define all elements (incl with key properties for assumptions)
		- again don't repeat definitions, apply them to state what you need to prove
		- part i. had good logic, ok explanation
		- part ii was almost entirely wrong - didn't use correct definition of injective, only the definition of a function
		- also remember to use template for proving subsets 

- **Practice Midterm #2** - 24/32  (75.00)
	- problem one - 6/8
		- kinda unnecessarily used contradiction
		- kinda long and wordy
		- otherwise, spot on logic
	- problem two - 8/8
		- FOL portions were good, just remember to check that formatting worked before submitting (\neq, not \noteq; \forall, not 'A')
	- problem three - 4/8
		- the logic was almost ok, but explained a little weakly
			- didn't account for the case where none of the statements were true
			- should have stuck to gut feeling about only comparing two statements at a time, not three
		- remember, anytime you're asked to prove that 'this is the only solution', thinking about breaking downthe other possible solutions into cases and disproving those
	- problem four - 6/8 
		- the logic was good, but the explanation involving q wasn't quite sufficient. I should have also repeated the logic *from* the perspective of q - define an arbitrary p, explore its properties, state what needs to be proven. then define an arbitrary q, explore its properties, connect it to that above need-to-prove statement.

- **Practice Midterm #3** - 26/32  (81.25)
	- problem one - 8/8
		- the explanations could have been a bit long
	- problem two - 8/8
		- remember to use the not operator instead of ! in final answer
	- problem three - 5/8
		- really go all out in defining variables (not just a copy of the theorem) ([] "Let S be an arbitrary set. Consider any sets A ∈ ℘(S) and B ∈ ℘(S). We need to prove..." instead of "We will prove that for any arbitrary setS, ifA∈p(S)andB∈p(S), then...")
		- done a little differently than key, which used cases and was shorter...but still ok I think?
	- problem four - 5/8 
		- could have been done without contradiction
		- didn't take full advantage of the generality of an arbitrary variable, but instead droned on too much