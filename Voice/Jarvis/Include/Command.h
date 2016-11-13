#ifndef COMMAND_H
#define COMMAND_H

#pragma once

namespace Jarvis {
  namespace Commands {
    class Command {
    public:
      virtual void execute() = 0;
    };
  }
}

#endif // COMMAND_H
