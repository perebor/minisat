/*
 * ProofVisitor.h
 *
 * Proof traversal functionality.
 *
 *  Created on: Jan 4, 2014
 *      Author: yakir
 */

#ifndef PROOF_VISITOR_H_
#define PROOF_VISITOR_H_

#include "SolverTypes.h"
#include "Solver.h"

namespace Minisat {

class ProofVisitor
{
public:
    ProofVisitor() {}

    virtual int visitResolvent      (Lit parent, Lit p1, CRef p2) { return 0; }
    virtual int visitChainResolvent (Lit parent)                  { return 0; }
    virtual int visitChainResolvent (CRef parent)                 { return 0; }

    vec<Lit>        chainPivots;
    vec<CRef>       chainClauses;
};

 class TraceProofVisitor : public ProofVisitor
 {
 protected:
   Solver &m_Solver;
   CMap<int> m_visited;

   vec<int> m_units;
   int m_ids;
   
   void doAntecendents ();
   
 public:
   TraceProofVisitor (Solver &solver) : m_Solver (solver), m_ids(1) 
   {
     m_units.growTo (m_Solver.nVars (), -1);
   }
   
   int visitResolvent (Lit parent, Lit p1, CRef p2);
   int visitChainResolvent (Lit parent);
   int visitChainResolvent (CRef parent);
 };
}

#endif /* G_PROOF_VISITOR_H_ */
