#pragma once

#include "humblenet.h"

#include <unordered_map>
#include <string>
#include <random>


namespace humblenet {

	struct P2PSignalConnection;

	typedef uint32_t GameId;

	struct Game {
		PeerId generateNewPeerId()
		{
                        static std::uniform_int_distribution<int> uid(1,INT_MAX); // random dice
			PeerId peerId = uid(rng); // use rng as a generator
			return peerId;
		}

		GameId gameId;

		PeerId nextPeerId;

		std::unordered_map<PeerId, P2PSignalConnection *> peers;  // not owned, must also be in signalConnections

		std::unordered_map<std::string, PeerId> aliases;

		Game(GameId game_id) : gameId(game_id), nextPeerId(1) { }

		void erasePeerAliases(PeerId p);
	};
}
