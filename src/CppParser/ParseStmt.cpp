// ----------------------------------------------------------------------------
// <auto-generated>
// This is autogenerated code by CppSharp.
// Do not edit this file or all your changes will be lost after re-generation.
// </auto-generated>
// ----------------------------------------------------------------------------


#include "AST.h"
#include "Parser.h"
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtCXX.h>

namespace CppSharp { namespace CppParser {

AST::Stmt* Parser::WalkStatement(const clang::Stmt* Stmt)
{
    if (Stmt == nullptr)
        return nullptr;

    AST::Stmt* _Stmt= 0;

    switch (Stmt->getStmtClass())
    {
    case clang::Stmt::DeclStmtClass:
    {
        auto S = const_cast<clang::DeclStmt*>(llvm::cast<clang::DeclStmt>(Stmt));
        auto _S = new AST::DeclStmt();
        _S->isSingleDecl = S->isSingleDecl();
        for (auto _E : S->decls())
        {
            auto _ES = WalkDeclaration(_E);
            _S->adddecls(_ES);
        }
        _Stmt = _S;
        break;
    }
    case clang::Stmt::NullStmtClass:
    {
        auto S = const_cast<clang::NullStmt*>(llvm::cast<clang::NullStmt>(Stmt));
        auto _S = new AST::NullStmt();
        _S->hasLeadingEmptyMacro = S->hasLeadingEmptyMacro();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CompoundStmtClass:
    {
        auto S = const_cast<clang::CompoundStmt*>(llvm::cast<clang::CompoundStmt>(Stmt));
        auto _S = new AST::CompoundStmt();
        _S->body_empty = S->body_empty();
        _S->size = S->size();
        for (auto _E : S->body())
        {
            auto _ES = WalkStatement(_E);
            _S->addbody(_ES);
        }
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CaseStmtClass:
    {
        auto S = const_cast<clang::CaseStmt*>(llvm::cast<clang::CaseStmt>(Stmt));
        auto _S = new AST::CaseStmt();
        _S->lHS = static_cast<AST::Expr*>(WalkExpression(S->getLHS()));
        _S->rHS = static_cast<AST::Expr*>(WalkExpression(S->getRHS()));
        _S->subStmt = static_cast<AST::Stmt*>(WalkStatement(S->getSubStmt()));
        _S->caseStmtIsGNURange = S->caseStmtIsGNURange();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::DefaultStmtClass:
    {
        auto S = const_cast<clang::DefaultStmt*>(llvm::cast<clang::DefaultStmt>(Stmt));
        auto _S = new AST::DefaultStmt();
        _S->subStmt = static_cast<AST::Stmt*>(WalkStatement(S->getSubStmt()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::LabelStmtClass:
    {
        auto S = const_cast<clang::LabelStmt*>(llvm::cast<clang::LabelStmt>(Stmt));
        auto _S = new AST::LabelStmt();
        _S->subStmt = static_cast<AST::Stmt*>(WalkStatement(S->getSubStmt()));
        _S->name = S->getName();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::AttributedStmtClass:
    {
        auto S = const_cast<clang::AttributedStmt*>(llvm::cast<clang::AttributedStmt>(Stmt));
        auto _S = new AST::AttributedStmt();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::IfStmtClass:
    {
        auto S = const_cast<clang::IfStmt*>(llvm::cast<clang::IfStmt>(Stmt));
        auto _S = new AST::IfStmt();
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->then = static_cast<AST::Stmt*>(WalkStatement(S->getThen()));
        _S->_else = static_cast<AST::Stmt*>(WalkStatement(S->getElse()));
        _S->init = static_cast<AST::Stmt*>(WalkStatement(S->getInit()));
        _S->_constexpr = S->isConstexpr();
        _S->hasInitStorage = S->hasInitStorage();
        _S->hasVarStorage = S->hasVarStorage();
        _S->hasElseStorage = S->hasElseStorage();
        _S->isObjCAvailabilityCheck = S->isObjCAvailabilityCheck();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::SwitchStmtClass:
    {
        auto S = const_cast<clang::SwitchStmt*>(llvm::cast<clang::SwitchStmt>(Stmt));
        auto _S = new AST::SwitchStmt();
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _S->init = static_cast<AST::Stmt*>(WalkStatement(S->getInit()));
        _S->hasInitStorage = S->hasInitStorage();
        _S->hasVarStorage = S->hasVarStorage();
        _S->isAllEnumCasesCovered = S->isAllEnumCasesCovered();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::WhileStmtClass:
    {
        auto S = const_cast<clang::WhileStmt*>(llvm::cast<clang::WhileStmt>(Stmt));
        auto _S = new AST::WhileStmt();
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _S->hasVarStorage = S->hasVarStorage();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::DoStmtClass:
    {
        auto S = const_cast<clang::DoStmt*>(llvm::cast<clang::DoStmt>(Stmt));
        auto _S = new AST::DoStmt();
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::ForStmtClass:
    {
        auto S = const_cast<clang::ForStmt*>(llvm::cast<clang::ForStmt>(Stmt));
        auto _S = new AST::ForStmt();
        _S->init = static_cast<AST::Stmt*>(WalkStatement(S->getInit()));
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->inc = static_cast<AST::Expr*>(WalkExpression(S->getInc()));
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _S->conditionVariableDeclStmt = static_cast<AST::DeclStmt*>(WalkStatement(S->getConditionVariableDeclStmt()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::GotoStmtClass:
    {
        auto S = const_cast<clang::GotoStmt*>(llvm::cast<clang::GotoStmt>(Stmt));
        auto _S = new AST::GotoStmt();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::IndirectGotoStmtClass:
    {
        auto S = const_cast<clang::IndirectGotoStmt*>(llvm::cast<clang::IndirectGotoStmt>(Stmt));
        auto _S = new AST::IndirectGotoStmt();
        _S->target = static_cast<AST::Expr*>(WalkExpression(S->getTarget()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::ContinueStmtClass:
    {
        auto S = const_cast<clang::ContinueStmt*>(llvm::cast<clang::ContinueStmt>(Stmt));
        auto _S = new AST::ContinueStmt();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::BreakStmtClass:
    {
        auto S = const_cast<clang::BreakStmt*>(llvm::cast<clang::BreakStmt>(Stmt));
        auto _S = new AST::BreakStmt();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::ReturnStmtClass:
    {
        auto S = const_cast<clang::ReturnStmt*>(llvm::cast<clang::ReturnStmt>(Stmt));
        auto _S = new AST::ReturnStmt();
        _S->retValue = static_cast<AST::Expr*>(WalkExpression(S->getRetValue()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::GCCAsmStmtClass:
    {
        auto S = const_cast<clang::GCCAsmStmt*>(llvm::cast<clang::GCCAsmStmt>(Stmt));
        auto _S = new AST::GCCAsmStmt();
        _S->simple = S->isSimple();
        _S->_volatile = S->isVolatile();
        _S->numOutputs = S->getNumOutputs();
        _S->numPlusOperands = S->getNumPlusOperands();
        _S->numInputs = S->getNumInputs();
        _S->numClobbers = S->getNumClobbers();
        for (auto _E : S->inputs())
        {
            auto _ES = WalkExpression(_E);
            _S->addinputs(_ES);
        }
        for (auto _E : S->outputs())
        {
            auto _ES = WalkExpression(_E);
            _S->addoutputs(_ES);
        }
        _Stmt = _S;
        break;
    }
    case clang::Stmt::MSAsmStmtClass:
    {
        auto S = const_cast<clang::MSAsmStmt*>(llvm::cast<clang::MSAsmStmt>(Stmt));
        auto _S = new AST::MSAsmStmt();
        _S->simple = S->isSimple();
        _S->_volatile = S->isVolatile();
        _S->numOutputs = S->getNumOutputs();
        _S->numPlusOperands = S->getNumPlusOperands();
        _S->numInputs = S->getNumInputs();
        _S->numClobbers = S->getNumClobbers();
        for (auto _E : S->inputs())
        {
            auto _ES = WalkExpression(_E);
            _S->addinputs(_ES);
        }
        for (auto _E : S->outputs())
        {
            auto _ES = WalkExpression(_E);
            _S->addoutputs(_ES);
        }
        _S->hasBraces = S->hasBraces();
        _S->numAsmToks = S->getNumAsmToks();
        _S->asmString = S->getAsmString();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::SEHExceptStmtClass:
    {
        auto S = const_cast<clang::SEHExceptStmt*>(llvm::cast<clang::SEHExceptStmt>(Stmt));
        auto _S = new AST::SEHExceptStmt();
        _S->filterExpr = static_cast<AST::Expr*>(WalkExpression(S->getFilterExpr()));
        _S->block = static_cast<AST::CompoundStmt*>(WalkStatement(S->getBlock()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::SEHFinallyStmtClass:
    {
        auto S = const_cast<clang::SEHFinallyStmt*>(llvm::cast<clang::SEHFinallyStmt>(Stmt));
        auto _S = new AST::SEHFinallyStmt();
        _S->block = static_cast<AST::CompoundStmt*>(WalkStatement(S->getBlock()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::SEHTryStmtClass:
    {
        auto S = const_cast<clang::SEHTryStmt*>(llvm::cast<clang::SEHTryStmt>(Stmt));
        auto _S = new AST::SEHTryStmt();
        _S->isCXXTry = S->getIsCXXTry();
        _S->tryBlock = static_cast<AST::CompoundStmt*>(WalkStatement(S->getTryBlock()));
        _S->handler = static_cast<AST::Stmt*>(WalkStatement(S->getHandler()));
        _S->exceptHandler = static_cast<AST::SEHExceptStmt*>(WalkStatement(S->getExceptHandler()));
        _S->finallyHandler = static_cast<AST::SEHFinallyStmt*>(WalkStatement(S->getFinallyHandler()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::SEHLeaveStmtClass:
    {
        auto S = const_cast<clang::SEHLeaveStmt*>(llvm::cast<clang::SEHLeaveStmt>(Stmt));
        auto _S = new AST::SEHLeaveStmt();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CapturedStmtClass:
    {
        auto S = const_cast<clang::CapturedStmt*>(llvm::cast<clang::CapturedStmt>(Stmt));
        auto _S = new AST::CapturedStmt();
        _S->capture_size = S->capture_size();
        for (auto _E : S->capture_inits())
        {
            auto _ES = WalkExpression(_E);
            _S->addcapture_inits(_ES);
        }
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CXXCatchStmtClass:
    {
        auto S = const_cast<clang::CXXCatchStmt*>(llvm::cast<clang::CXXCatchStmt>(Stmt));
        auto _S = new AST::CXXCatchStmt();
        _S->caughtType = GetQualifiedType(S->getCaughtType());
        _S->handlerBlock = static_cast<AST::Stmt*>(WalkStatement(S->getHandlerBlock()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CXXTryStmtClass:
    {
        auto S = const_cast<clang::CXXTryStmt*>(llvm::cast<clang::CXXTryStmt>(Stmt));
        auto _S = new AST::CXXTryStmt();
        _S->numHandlers = S->getNumHandlers();
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CXXForRangeStmtClass:
    {
        auto S = const_cast<clang::CXXForRangeStmt*>(llvm::cast<clang::CXXForRangeStmt>(Stmt));
        auto _S = new AST::CXXForRangeStmt();
        _S->init = static_cast<AST::Stmt*>(WalkStatement(S->getInit()));
        _S->rangeInit = static_cast<AST::Expr*>(WalkExpression(S->getRangeInit()));
        _S->cond = static_cast<AST::Expr*>(WalkExpression(S->getCond()));
        _S->inc = static_cast<AST::Expr*>(WalkExpression(S->getInc()));
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::MSDependentExistsStmtClass:
    {
        auto S = const_cast<clang::MSDependentExistsStmt*>(llvm::cast<clang::MSDependentExistsStmt>(Stmt));
        auto _S = new AST::MSDependentExistsStmt();
        _S->isIfExists = S->isIfExists();
        _S->isIfNotExists = S->isIfNotExists();
        _S->subStmt = static_cast<AST::CompoundStmt*>(WalkStatement(S->getSubStmt()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CoroutineBodyStmtClass:
    {
        auto S = const_cast<clang::CoroutineBodyStmt*>(llvm::cast<clang::CoroutineBodyStmt>(Stmt));
        auto _S = new AST::CoroutineBodyStmt();
        _S->hasDependentPromiseType = S->hasDependentPromiseType();
        _S->body = static_cast<AST::Stmt*>(WalkStatement(S->getBody()));
        _S->promiseDeclStmt = static_cast<AST::Stmt*>(WalkStatement(S->getPromiseDeclStmt()));
        _S->initSuspendStmt = static_cast<AST::Stmt*>(WalkStatement(S->getInitSuspendStmt()));
        _S->finalSuspendStmt = static_cast<AST::Stmt*>(WalkStatement(S->getFinalSuspendStmt()));
        _S->exceptionHandler = static_cast<AST::Stmt*>(WalkStatement(S->getExceptionHandler()));
        _S->fallthroughHandler = static_cast<AST::Stmt*>(WalkStatement(S->getFallthroughHandler()));
        _S->allocate = static_cast<AST::Expr*>(WalkExpression(S->getAllocate()));
        _S->deallocate = static_cast<AST::Expr*>(WalkExpression(S->getDeallocate()));
        _S->returnValueInit = static_cast<AST::Expr*>(WalkExpression(S->getReturnValueInit()));
        _S->resultDecl = static_cast<AST::Stmt*>(WalkStatement(S->getResultDecl()));
        _S->returnStmt = static_cast<AST::Stmt*>(WalkStatement(S->getReturnStmt()));
        _S->returnStmtOnAllocFailure = static_cast<AST::Stmt*>(WalkStatement(S->getReturnStmtOnAllocFailure()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::CoreturnStmtClass:
    {
        auto S = const_cast<clang::CoreturnStmt*>(llvm::cast<clang::CoreturnStmt>(Stmt));
        auto _S = new AST::CoreturnStmt();
        _S->isImplicit = S->isImplicit();
        _S->operand = static_cast<AST::Expr*>(WalkExpression(S->getOperand()));
        _S->promiseCall = static_cast<AST::Expr*>(WalkExpression(S->getPromiseCall()));
        _Stmt = _S;
        break;
    }
    case clang::Stmt::ConstantExprClass:
    case clang::Stmt::OpaqueValueExprClass:
    case clang::Stmt::DeclRefExprClass:
    case clang::Stmt::IntegerLiteralClass:
    case clang::Stmt::FixedPointLiteralClass:
    case clang::Stmt::CharacterLiteralClass:
    case clang::Stmt::FloatingLiteralClass:
    case clang::Stmt::ImaginaryLiteralClass:
    case clang::Stmt::StringLiteralClass:
    case clang::Stmt::PredefinedExprClass:
    case clang::Stmt::ParenExprClass:
    case clang::Stmt::UnaryOperatorClass:
    case clang::Stmt::OffsetOfExprClass:
    case clang::Stmt::UnaryExprOrTypeTraitExprClass:
    case clang::Stmt::ArraySubscriptExprClass:
    case clang::Stmt::CallExprClass:
    case clang::Stmt::MemberExprClass:
    case clang::Stmt::CompoundLiteralExprClass:
    case clang::Stmt::ImplicitCastExprClass:
    case clang::Stmt::CStyleCastExprClass:
    case clang::Stmt::BinaryOperatorClass:
    case clang::Stmt::CompoundAssignOperatorClass:
    case clang::Stmt::ConditionalOperatorClass:
    case clang::Stmt::BinaryConditionalOperatorClass:
    case clang::Stmt::AddrLabelExprClass:
    case clang::Stmt::StmtExprClass:
    case clang::Stmt::ShuffleVectorExprClass:
    case clang::Stmt::ConvertVectorExprClass:
    case clang::Stmt::ChooseExprClass:
    case clang::Stmt::GNUNullExprClass:
    case clang::Stmt::VAArgExprClass:
    case clang::Stmt::InitListExprClass:
    case clang::Stmt::DesignatedInitExprClass:
    case clang::Stmt::NoInitExprClass:
    case clang::Stmt::DesignatedInitUpdateExprClass:
    case clang::Stmt::ArrayInitLoopExprClass:
    case clang::Stmt::ArrayInitIndexExprClass:
    case clang::Stmt::ImplicitValueInitExprClass:
    case clang::Stmt::ParenListExprClass:
    case clang::Stmt::GenericSelectionExprClass:
    case clang::Stmt::ExtVectorElementExprClass:
    case clang::Stmt::BlockExprClass:
    case clang::Stmt::AsTypeExprClass:
    case clang::Stmt::PseudoObjectExprClass:
    case clang::Stmt::AtomicExprClass:
    case clang::Stmt::TypoExprClass:
    case clang::Stmt::CXXOperatorCallExprClass:
    case clang::Stmt::CXXMemberCallExprClass:
    case clang::Stmt::CUDAKernelCallExprClass:
    case clang::Stmt::CXXStaticCastExprClass:
    case clang::Stmt::CXXDynamicCastExprClass:
    case clang::Stmt::CXXReinterpretCastExprClass:
    case clang::Stmt::CXXConstCastExprClass:
    case clang::Stmt::UserDefinedLiteralClass:
    case clang::Stmt::CXXBoolLiteralExprClass:
    case clang::Stmt::CXXNullPtrLiteralExprClass:
    case clang::Stmt::CXXStdInitializerListExprClass:
    case clang::Stmt::CXXTypeidExprClass:
    case clang::Stmt::MSPropertyRefExprClass:
    case clang::Stmt::MSPropertySubscriptExprClass:
    case clang::Stmt::CXXUuidofExprClass:
    case clang::Stmt::CXXThisExprClass:
    case clang::Stmt::CXXThrowExprClass:
    case clang::Stmt::CXXDefaultArgExprClass:
    case clang::Stmt::CXXDefaultInitExprClass:
    case clang::Stmt::CXXBindTemporaryExprClass:
    case clang::Stmt::CXXConstructExprClass:
    case clang::Stmt::CXXInheritedCtorInitExprClass:
    case clang::Stmt::CXXFunctionalCastExprClass:
    case clang::Stmt::CXXTemporaryObjectExprClass:
    case clang::Stmt::LambdaExprClass:
    case clang::Stmt::CXXScalarValueInitExprClass:
    case clang::Stmt::CXXNewExprClass:
    case clang::Stmt::CXXDeleteExprClass:
    case clang::Stmt::CXXPseudoDestructorExprClass:
    case clang::Stmt::TypeTraitExprClass:
    case clang::Stmt::ArrayTypeTraitExprClass:
    case clang::Stmt::ExpressionTraitExprClass:
    case clang::Stmt::UnresolvedLookupExprClass:
    case clang::Stmt::DependentScopeDeclRefExprClass:
    case clang::Stmt::ExprWithCleanupsClass:
    case clang::Stmt::CXXUnresolvedConstructExprClass:
    case clang::Stmt::CXXDependentScopeMemberExprClass:
    case clang::Stmt::UnresolvedMemberExprClass:
    case clang::Stmt::CXXNoexceptExprClass:
    case clang::Stmt::PackExpansionExprClass:
    case clang::Stmt::SizeOfPackExprClass:
    case clang::Stmt::SubstNonTypeTemplateParmExprClass:
    case clang::Stmt::SubstNonTypeTemplateParmPackExprClass:
    case clang::Stmt::FunctionParmPackExprClass:
    case clang::Stmt::MaterializeTemporaryExprClass:
    case clang::Stmt::CXXFoldExprClass:
    case clang::Stmt::CoawaitExprClass:
    case clang::Stmt::DependentCoawaitExprClass:
    case clang::Stmt::CoyieldExprClass:
    {
        return WalkExpression(llvm::cast<clang::Expr>(Stmt));
    }
    default:
        printf("Unhandled statement kind: %s\n", Stmt->getStmtClassName());
    }

    return _Stmt;
}

} }