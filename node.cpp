//
// Created by Alexey Valevich on 14/11/2020.
//

#include "node.h"


bool EmptyNode::Evaluate(const Date& date, const string& event) const  {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch (cmp_) {
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
        default:
            return false;
    }
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch (cmp_) {
        case Comparison::Less:
            return event < value;
        case Comparison::LessOrEqual:
            return event <= value;
        case Comparison::Greater:
            return event > value;
        case Comparison::GreaterOrEqual:
            return event >= value;
        case Comparison::Equal:
            return event == value;
        case Comparison::NotEqual:
            return event != value;
        default:
            return false;
    }
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch (logical_operation) {
        case LogicalOperation::And:
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
        case LogicalOperation::Or:
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
        default:
            return false;
    }
}