//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "MooseApp.h"

class cpg_appApp;

template <>
InputParameters validParams<cpg_appApp>();

class cpg_appApp : public MooseApp
{
public:
  cpg_appApp(InputParameters parameters);
  virtual ~cpg_appApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

