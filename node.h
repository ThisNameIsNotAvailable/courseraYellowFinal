//
// Created by Alexey on 14/11/2020.
//

#pragma once

#include "date.h"

#include <memory>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& d) : cmp_(cmp), date_(d) {}
    bool Evaluate(const Date& date, const string& event) const override;

private:
    const Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const string& val) : cmp_(cmp), value(val) {}
    bool Evaluate(const Date& date, const string& event) const override;

private:
    const Comparison cmp_;
    const string value;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation logicOP, const shared_ptr<Node>& left, const shared_ptr<Node>& right) :
                            logical_operation(logicOP), left_(left), right_(right){}
    bool Evaluate(const Date& date, const string& event) const override;

private:
    const LogicalOperation logical_operation;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};
